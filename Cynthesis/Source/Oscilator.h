/*
  ==============================================================================

    Oscilator.h
    Created: 20 Mar 2019 12:46:37pm
    Author:  Duncan Hall

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class Oscilator
{
public:	//this section allows for Oscilator.____ other stuff calls this
 //these will be used by getSample:
	float phase;
	int semitones;
	int cents;
	float volume = 0.5;
	float frequency = 440;
	double currentAngle = 0.0;
	double sampleRate;
	double realFrequency;

	float getSample(double lfoState) {
		realFrequency = frequency * pow(2, (semitones + cents/100 + lfoState)/12.0);
		currentAngle += realFrequency * MathConstants<double>::twoPi / sampleRate;
		return (float) sin(currentAngle + phase * MathConstants<double>::twoPi) * volume;
	}

private: //helper functions & private variables for Oscilator class only
};
