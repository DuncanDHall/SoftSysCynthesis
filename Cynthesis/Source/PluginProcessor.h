/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "SynthVoice.h"

//==============================================================================
/**
*/
class CynthesisAudioProcessor  : public AudioProcessor
{
public:
	double noteOnVel = 100.0; //This is the variable that we will set with the
	// slider.
	
	//==========================================================================
    CynthesisAudioProcessor();
    ~CynthesisAudioProcessor();

    //==========================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==========================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==========================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==========================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==========================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    //==========================================================================
    // CUSTOM
    //==========================================================================
    void setGain(double gain);

	
private:
    //==========================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CynthesisAudioProcessor)
    
    Synthesiser synth;
    SynthVoice *synthVoice;
    
    int synthVoiceCount = 5;
    
    double lastSampleRate;
};
