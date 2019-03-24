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

    // gainSlider config //
    addAndMakeVisible(&gainSlider);
    gainSlider.setSliderStyle(Slider::LinearBarVertical);
    gainSlider.setRange(0, 1.0, 0.02);
    gainSlider.setTextBoxStyle(Slider::NoTextBox, true, 90, 0);
    gainSlider.setPopupDisplayEnabled(true, false, this);
    gainSlider.setTextValueSuffix(" Gain");
    gainSlider.setValue(1.0);
    gainSlider.addListener(this);

    // gainLabel
    addAndMakeVisible(&gainLabel);
    gainLabel.setText("Gain", dontSendNotification);
    gainLabel.setFont(labelFont);
    gainLabel.setColour(Label::textColourId, Colours::white);
    gainLabel.setJustificationType(Justification::centred);
    gainLabel.setVisible(true);

    resized();
}

CynthesisAudioProcessorEditor::~CynthesisAudioProcessorEditor()
{
}

//==============================================================================

void CynthesisAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    if (slider == &gainSlider) {
        processor.setGain(slider->getValue());
    }
}

void CynthesisAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (16.0f);

    g.drawFittedText ("Midi Volume by Cynthesis!", getLocalBounds(), Justification::centred, 1);
}

void CynthesisAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    int fontSize = (int) labelFont.getHeight();
    int textMargin = 10;
    int vertPadding = 30;
    int horizPadding = 30;
    int sliderHeight = getHeight() - 2*vertPadding - 2*textMargin - fontSize;
    int sliderWidth = 20;
    int horizSpacing = 10;

    // temporary variables for intermediate computations
    int x, y, w, h;

    // gainSlider
    x = getWidth() - horizPadding - sliderWidth;
    y = vertPadding + 2*textMargin + fontSize;
	gainSlider.setBounds(x, y, sliderWidth, sliderHeight);

	// gainLabel
//	gainLabel.attachToComponent(&gainSlider, false);
	w = labelFont.getStringWidth(gainLabel.getText());
	h = fontSize;
	x = gainSlider.getBounds().getCentreX() - w/2;
	y = gainSlider.getBounds().getY() - textMargin - fontSize;
	gainLabel.setBounds(x, y, w, h);
}
