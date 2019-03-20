/*
  ==============================================================================

    SynthVoice.h
    Created: 20 Mar 2019 11:48:42am
    Author:  Duncan Hall

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class SynthVoice : public SynthesiserVoice
{
public:
    /*
     to know what functions must be defined here, look for functions marked
     virtual and =0 in the documentation
     https://docs.juce.com/master/classSynthesiserVoice.html
     */
    bool canPlaySound(SynthesiserSound * sound)
    {
        // this fanciness tries to case as a SynthSound, and fails as a
        // nullptr thus returning false
        return dynamic_cast<SynthSound*>(sound) != nullptr;
    }
    
    //==========================================================================
    
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound *sound, int currentPitcchWheelPosition)
    {
        level = velocity;  // note this velocity ranges 0.0 to 1.0
        frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        std::cout << midiNoteNumber << std::endl;
    }
    
    //==========================================================================
    
    void stopNote (float velocity, bool allowTailOff)
    {
        level = 0;
        clearCurrentNote();
    }
    
    //==========================================================================
    
    void pitchWheelMoved (int newPitchWheelValue)
    {
        
    }
    
    //==========================================================================
    
    void controllerMoved (int controllerNumber, int newControllerValue)
    {
        
    }
    
    //==========================================================================
    
    void aftertouchChanged (int newAftertouchValue)
    {
        
    }
    
    //==========================================================================
    
    void renderNextBlock (AudioBuffer< float > &outputBuffer, int startSample, int numSamples)
    {
        for (int sample = 0; sample < numSamples; ++sample) {
            for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel) {
                // currently writing random samples
                // output should be scaled -1.0 to 1.0
                auto currentSample = (float) ((random.nextFloat() * 0.1 - 0.05) * level);
                outputBuffer.addSample(channel, startSample, currentSample);
            }
            startSample++;
        }
    }
    
    //==========================================================================
    
private:
    double level = 0;
    double frequency;
    
    Random random;
};
