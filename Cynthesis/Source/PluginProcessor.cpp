/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

#include "SynthSound.h"
#include "SynthVoice.h"

//==============================================================================
CynthesisAudioProcessor::CynthesisAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    // not sure why this clearing is necessary
    synth.clearVoices();
    // this makes sense, now we have
    for (int i = 0; i < synthVoiceCount; i++) {
        synth.addVoice(new SynthVoice());
    }
    

	string strMytestString("hello world");
	cout << strMytestString;

    // again, more mysterious clearing
    synth.clearSounds();
    // add the sounds
    synth.addSound(new SynthSound());
}

CynthesisAudioProcessor::~CynthesisAudioProcessor()
{
}

//==============================================================================
const String CynthesisAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool CynthesisAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool CynthesisAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool CynthesisAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double CynthesisAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int CynthesisAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int CynthesisAudioProcessor::getCurrentProgram()
{
    return 0;
}

void CynthesisAudioProcessor::setCurrentProgram (int index)
{
}

const String CynthesisAudioProcessor::getProgramName (int index)
{
    return {};
}

void CynthesisAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void CynthesisAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
	lastSampleRate = sampleRate;
	synth.setCurrentPlaybackSampleRate(lastSampleRate); //passes sample rate to synthesizer object
    for (int i = 0; i < synth.getNumVoices(); ++i) {
        synth.getVoice(i)->setCurrentPlaybackSampleRate(lastSampleRate);
    }
}

void CynthesisAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool CynthesisAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void CynthesisAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    // TODO: get rid of thise boilerplate if unneeded
    //    ScopedNoDenormals noDenormals;
    //    auto totalNumInputChannels  = getTotalNumInputChannels();
    //    auto totalNumOutputChannels = getTotalNumOutputChannels();
    //
    //    // In case we have more outputs than inputs, this code clears any output
    //    // channels that didn't contain input data, (because these aren't
    //    // guaranteed to be empty - they may contain garbage).
    //    // This is here to avoid people getting screaming feedback
    //    // when they first compile a plugin, but obviously you don't need to keep
    //    // this code if your algorithm always overwrites all the output channels.
    //    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
    //        buffer.clear (i, 0, buffer.getNumSamples());
    //
    //    // This is the place where you'd normally do the guts of your plugin's
    //    // audio processing...
    //    // Make sure to reset the state if your inner loop is processing
    //    // the samples and the outer loop is handling the channels.
    //    // Alternatively, you can process the samples with the channels
    //    // interleaved by keeping the same state.
    //    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    //    {
    //        auto* channelData = buffer.getWritePointer (channel);
    //
    //        // ..do something to the data...
    //    }
    
    // clear the buffer
    buffer.clear();
    // delegate midi block handling to the synth
    synth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
}

//==============================================================================
bool CynthesisAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* CynthesisAudioProcessor::createEditor()
{
    return new CynthesisAudioProcessorEditor (*this);
}

//==============================================================================
void CynthesisAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void CynthesisAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

void CynthesisAudioProcessor::setGain(double gain)
{
    for (int i = 0; i < synth.getNumVoices(); i++) {
        SynthVoice *sv = dynamic_cast<SynthVoice *>(synth.getVoice(i));
        if (sv) {
            sv->setGain(gain);
        }
    }
}


//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new CynthesisAudioProcessor();
}
