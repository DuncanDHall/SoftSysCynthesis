/*
  ==============================================================================

    SynthVoice.h
    Created: 20 Mar 2019 11:48:42am
    Author:  Duncan Hall

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscilator.h"
#include <string>
#include <iostream>

using namespace std;

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
        this->velocity = velocity;  // note this velocity ranges 0.0 to 1.0
        frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        std::cout << midiNoteNumber << std::endl;
        
		//set oscilator frequencies
		//cout << osc1.frequency << " is divisible by" << endl;
		osc1.frequency = frequency;
		//osc2.frequency = frequency;

    }
    
    //==========================================================================
    
    void stopNote (float velocity, bool allowTailOff)
    {
        this->velocity = 0;
        clearCurrentNote();
    }
    
    //==========================================================================
    
    void pitchWheelMoved (int newPitchWheelValue)
    {}
    
    //==========================================================================
    
    void controllerMoved (int controllerNumber, int newControllerValue)
    {}
    
    //==========================================================================
    
    void aftertouchChanged (int newAftertouchValue)
    {}
    
    //==========================================================================
    
    void renderNextBlock (AudioBuffer< float > &outputBuffer, int startSample, int numSamples)
    {
        for (int sample = 0; sample < numSamples; ++sample) {
            for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel) {
                // currently writing random samples
                // output should be scaled -1.0 to 1.0
//                auto currentSample = (float) ((random.nextFloat() * 0.1 - 0.05) * velocity);
//                outputBuffer.addSample(channel, startSample, currentSample);
				  outputBuffer.addSample(channel, startSample, getSample(startSample)); //startSample is current sample)
			}
			startSample++; //increments sample
        }
    }
    
    //==========================================================================
    // CUSTOM
    //==========================================================================
    void setGain(double gain) {
        this->gain = gain;
    }

private:
	// calculates the correct sample value to write
	// takes in: currentSample, analogous to time variable (scaled by sample rate) 
	// output should be scaled -1.0 to 1.0
	float getSample(int currentSample)
	{
		double rate = getSampleRate(); //get rate from SynthesiserVoice
		double time = currentSample / rate; //current sample divided by sample rate will give time in seconds

		//wants to get current values from each oscillator 

		// TODO: do the FM synthesis math here
		float amplitude_1 = osc1.getSample(time); //updating from oscillator: what is its current value
		//float amplitude_2 = osc2.getSample(time); //same

		float signal = (amplitude_1) * velocity * gain; //scaling by velocity and gain
		//float signal = (amplitude_1 + amplitude_2)* velocity * gain; //scaling by velocity and gain

		return signal;
	}

    //==========================================================================
                     
    double velocity = 0;
    double gain = 1.0;
    double frequency;
    
    Random random;
    
    
    // TODO – these might need to be initialized differently
    Oscilator osc1;
    Oscilator osc2;

    
    Oscilator lfo;
};
