/*
  ==============================================================================
	Ilya's progress, day #1:

    THIS IS A BASIC THING.
    
    PROBABLY A SIMPLE VOLUME SHIFTER

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
CynthesisAudioProcessorEditor::CynthesisAudioProcessorEditor (CynthesisAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 600);

	// these define the parameters of our slider object
	midiVolume.setSliderStyle(Slider::LinearBarVertical);
	midiVolume.setRange(0.0, 127.0, 1.0);
	midiVolume.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
	midiVolume.setPopupDisplayEnabled(true, false, this);
	midiVolume.setTextValueSuffix(" Volume");
	midiVolume.setValue(100.0);
	// this function adds the slider to the editor
	addAndMakeVisible(&midiVolume);

	// add the listener to the slider
	midiVolume.addListener(this);

}

CynthesisAudioProcessorEditor::~CynthesisAudioProcessorEditor()
{
}

//==============================================================================

void CynthesisAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
	processor.noteOnVel = midiVolume.getValue();
}

void CynthesisAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (30.0f);
    g.drawFittedText ("Midi Volume by Cynthesis!", getLocalBounds(), Justification::centred, 1);
}

void CynthesisAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

	// sets the position and size of the slider with arguments (x, y, width, height)
	midiVolume.setBounds(40, 30, 20, getHeight() - 60);
}
