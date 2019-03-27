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
class CynthesisAudioProcessorEditor : public AudioProcessorEditor, private
        Slider::Listener
{
public:
    CynthesisAudioProcessorEditor (CynthesisAudioProcessor&);
    ~CynthesisAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:

    void sliderValueChanged(Slider* slider) override;

	// This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    CynthesisAudioProcessor& processor;

    // Styling
    Font titleFont = Font(40.0f, Font::bold);
    Font headerFont = Font(30.0f, Font::plain);
    Font labelFont = Font(20.0f, Font::plain);

    // title
    Label titleLabel;

    // gain
    Label gainLabel;
    Slider gainSlider;


    //////////
    // Osc1 //
    //////////
    Label headerOsc1;
    Label phaseLabelOsc1;
    Slider phaseSliderOsc1;
    Label semitonesLabelOsc1;
    Slider semitonesSliderOsc1;
    Label centsLabelOsc1;
    Slider centsSliderOsc1;
    Label volumeLabelOsc1;
    Slider volumeSliderOsc1;


    //////////
    // Osc2 //
    //////////
    Label headerOsc2;
    Label phaseLabelOsc2;
    Slider phaseSliderOsc2;
    Label semitonesLabelOsc2;
    Slider semitonesSliderOsc2;
    Label centsLabelOsc2;
    Slider centsSliderOsc2;
    Label volumeLabelOsc2;
    Slider volumeSliderOsc2;


    /////////
    // LFO //
    /////////
    Label headerLFO;
    Label frequencyLabelLFO;
    Slider frequencySliderLFO;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CynthesisAudioProcessorEditor)
};
