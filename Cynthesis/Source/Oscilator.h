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

	float getSample(double time) {
		double dOutput = sin(frequency * 2.0 * 3.14159 * time);
		return dOutput * volume;
	}

private: //helper functions & private variables for Oscilator class only
};
