/*
  ==============================================================================

    SimpleSynth.h
    Created: 15 Mar 2019 9:48:44am
    Author:  Duncan Hall

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class SimpleSynth : public Synthesiser {
public:
    void setup();
private:
    // manager object that finds an appropriate way to decode various audio files.  Used with SampleSound objects.
    AudioFormatManager audioFormatManager;
};
