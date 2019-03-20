/*
  ==============================================================================

    SynthSound.h
    Created: 20 Mar 2019 11:48:34am
    Author:  Duncan Hall

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class SynthSound : public SynthesiserSound
{
public:
    // regardless of midi note number, this voice should play
    bool appliesToNote (int /*midiNoteNumber*/) { return true; }
    // regardless of midi channel, this voice should play
    bool appliesToChannel (int /*midiChannel*/) { return true; }
};
