/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class Cynthesis_01AudioProcessorEditor  : public AudioProcessorEditor
{
public:
    Cynthesis_01AudioProcessorEditor (Cynthesis_01AudioProcessor&);
    ~Cynthesis_01AudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Cynthesis_01AudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Cynthesis_01AudioProcessorEditor)
};
