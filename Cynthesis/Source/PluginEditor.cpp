/*
  ==============================================================================
	Ilya's progress, day #1:

    THIS IS A BASIC THING.
    
    PROBABLY A SIMPLE VOLUME SHIFTER

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//#include "stdafx.h"
#include <string>
#include <iostream>

//==============================================================================
CynthesisAudioProcessorEditor::CynthesisAudioProcessorEditor (CynthesisAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 630);

    // titleLabel
    addAndMakeVisible(titleLabel);
    titleLabel.setText("Cynthesis", dontSendNotification);
    titleLabel.setFont(titleFont);
    titleLabel.setJustificationType(Justification::left);

    // gainLabel
    addAndMakeVisible(&gainLabel);
    gainLabel.setText("Gain", dontSendNotification);
    gainLabel.setFont(labelFont);
    gainLabel.setJustificationType(Justification::centred);
//    gainLabel.setColour(Label::textColourId, Colours::white);
//    gainLabel.setVisible(true);
    // gainSlider config //
    addAndMakeVisible(&gainSlider);
    gainSlider.setSliderStyle(Slider::LinearBarVertical);
    gainSlider.setRange(0, 1.0, 0.02);
    gainSlider.setTextBoxStyle(Slider::NoTextBox, true, 90, 0);
    gainSlider.setPopupDisplayEnabled(true, true, this);
    gainSlider.setTextValueSuffix(" Gain");
    gainSlider.setValue(1.0);
    gainSlider.addListener(this);


    //////////
    // Osc1 //
    //////////

    // headerOsc1
    addAndMakeVisible(headerOsc1);
    headerOsc1.setText("Osc1", dontSendNotification);
    headerOsc1.setFont(headerFont);
    headerOsc1.setJustificationType(Justification::centred);

    // phaseLabelOsc1
    addAndMakeVisible(phaseLabelOsc1);
    phaseLabelOsc1.setText("phase", dontSendNotification);
    phaseLabelOsc1.setFont(labelFont);
    phaseLabelOsc1.setJustificationType(Justification::centred);
    // phaseSliderOsc1
    addAndMakeVisible(phaseSliderOsc1);
    phaseSliderOsc1.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    phaseSliderOsc1.setRange(0, 1.0, 0.01);
    phaseSliderOsc1.setTextBoxStyle(Slider::NoTextBox, true, 90, 0);
    phaseSliderOsc1.setPopupDisplayEnabled(true, true, this);
    phaseSliderOsc1.setTextValueSuffix(" phase");
    phaseSliderOsc1.setValue(0.0);
    phaseSliderOsc1.addListener(this);

    // semitonesLabelOsc1
    addAndMakeVisible(semitonesLabelOsc1);
    semitonesLabelOsc1.setText("semitones", dontSendNotification);
    semitonesLabelOsc1.setFont(labelFont);
    semitonesLabelOsc1.setJustificationType(Justification::centred);
    // semitonesSliderOsc1
    addAndMakeVisible(semitonesSliderOsc1);
    semitonesSliderOsc1.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    semitonesSliderOsc1.setRange(-24, 24, 1);
    semitonesSliderOsc1.setTextBoxStyle(Slider::NoTextBox, true, 90, 0);
    semitonesSliderOsc1.setPopupDisplayEnabled(true, true, this);
    semitonesSliderOsc1.setTextValueSuffix(" semitones");
    semitonesSliderOsc1.setValue(0);
    semitonesSliderOsc1.addListener(this);

    // centsLabelOsc1
    addAndMakeVisible(centsLabelOsc1);
    centsLabelOsc1.setText("cents", dontSendNotification);
    centsLabelOsc1.setFont(labelFont);
    centsLabelOsc1.setJustificationType(Justification::centred);
    // centsSliderOsc1
    addAndMakeVisible(centsSliderOsc1);
    centsSliderOsc1.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    centsSliderOsc1.setRange(-50, 50, 1);
    centsSliderOsc1.setTextBoxStyle(Slider::NoTextBox, true, 90, 0);
    centsSliderOsc1.setPopupDisplayEnabled(true, true, this);
    centsSliderOsc1.setTextValueSuffix(" cents");
    centsSliderOsc1.setValue(0);
    centsSliderOsc1.addListener(this);

    // volumeLabelOsc1
    addAndMakeVisible(volumeLabelOsc1);
    volumeLabelOsc1.setText("volume", dontSendNotification);
    volumeLabelOsc1.setFont(labelFont);
    volumeLabelOsc1.setJustificationType(Justification::centred);
    // volumeSliderOsc1
    addAndMakeVisible(volumeSliderOsc1);
    volumeSliderOsc1.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    volumeSliderOsc1.setRange(0, 1.0, 0.01);
    volumeSliderOsc1.setTextBoxStyle(Slider::NoTextBox, true, 90, 0);
    volumeSliderOsc1.setPopupDisplayEnabled(true, true, this);
    volumeSliderOsc1.setTextValueSuffix(" osc volume");
    volumeSliderOsc1.setValue(0.7);
    volumeSliderOsc1.addListener(this);


    //////////
    // Osc2 //
    //////////

    // headerOsc2
    addAndMakeVisible(headerOsc2);
    headerOsc2.setText("Osc2", dontSendNotification);
    headerOsc2.setFont(headerFont);
    headerOsc2.setJustificationType(Justification::centred);

    // phaseLabelOsc2
    addAndMakeVisible(phaseLabelOsc2);
    phaseLabelOsc2.setText("phase", dontSendNotification);
    phaseLabelOsc2.setFont(labelFont);
    phaseLabelOsc2.setJustificationType(Justification::centred);
    // phaseSliderOsc2
    addAndMakeVisible(phaseSliderOsc2);
    phaseSliderOsc2.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    phaseSliderOsc2.setRange(0, 1.0, 0.01);
    phaseSliderOsc2.setTextBoxStyle(Slider::NoTextBox, true, 90, 0);
    phaseSliderOsc2.setPopupDisplayEnabled(true, true, this);
    phaseSliderOsc2.setTextValueSuffix(" phase");
    phaseSliderOsc2.setValue(0.0);
    phaseSliderOsc2.addListener(this);

    // semitonesLabelOsc2
    addAndMakeVisible(semitonesLabelOsc2);
    semitonesLabelOsc2.setText("semitones", dontSendNotification);
    semitonesLabelOsc2.setFont(labelFont);
    semitonesLabelOsc2.setJustificationType(Justification::centred);
    // semitonesSliderOsc2
    addAndMakeVisible(semitonesSliderOsc2);
    semitonesSliderOsc2.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    semitonesSliderOsc2.setRange(-24, 24, 1);
    semitonesSliderOsc2.setTextBoxStyle(Slider::NoTextBox, true, 90, 0);
    semitonesSliderOsc2.setPopupDisplayEnabled(true, true, this);
    semitonesSliderOsc2.setTextValueSuffix(" semitones");
    semitonesSliderOsc2.setValue(0);
    semitonesSliderOsc2.addListener(this);

    // centsLabelOsc2
    addAndMakeVisible(centsLabelOsc2);
    centsLabelOsc2.setText("cents", dontSendNotification);
    centsLabelOsc2.setFont(labelFont);
    centsLabelOsc2.setJustificationType(Justification::centred);
    // centsSliderOsc2
    addAndMakeVisible(centsSliderOsc2);
    centsSliderOsc2.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    centsSliderOsc2.setRange(-50, 50, 1);
    centsSliderOsc2.setTextBoxStyle(Slider::NoTextBox, true, 90, 0);
    centsSliderOsc2.setPopupDisplayEnabled(true, true, this);
    centsSliderOsc2.setTextValueSuffix(" cents");
    centsSliderOsc2.setValue(0);
    centsSliderOsc2.addListener(this);

    // volumeLabelOsc2
    addAndMakeVisible(volumeLabelOsc2);
    volumeLabelOsc2.setText("volume", dontSendNotification);
    volumeLabelOsc2.setFont(labelFont);
    volumeLabelOsc2.setJustificationType(Justification::centred);
    // volumeSliderOsc2
    addAndMakeVisible(volumeSliderOsc2);
    volumeSliderOsc2.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    volumeSliderOsc2.setRange(0, 1.0, 0.01);
    volumeSliderOsc2.setTextBoxStyle(Slider::NoTextBox, true, 90, 0);
    volumeSliderOsc2.setPopupDisplayEnabled(true, true, this);
    volumeSliderOsc2.setTextValueSuffix(" osc volume");
    volumeSliderOsc2.setValue(0.7);
    volumeSliderOsc2.addListener(this);


    /////////
    // LFO //
    /////////

    // headerLFO
    addAndMakeVisible(headerLFO);
    headerLFO.setText("LFO", dontSendNotification);
    headerLFO.setFont(headerFont);
    headerLFO.setJustificationType(Justification::centred);

    // frequencyLabelLFO
    addAndMakeVisible(frequencyLabelLFO);
    frequencyLabelLFO.setText("frequency", dontSendNotification);
    frequencyLabelLFO.setFont(labelFont);
    frequencyLabelLFO.setJustificationType(Justification::centred);
    // frequencySliderLFO
    addAndMakeVisible(frequencySliderLFO);
    frequencySliderLFO.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    frequencySliderLFO.setRange(0.5, 30.0, 0.05);
    frequencySliderLFO.setTextBoxStyle(Slider::NoTextBox, true, 90, 0);
    frequencySliderLFO.setPopupDisplayEnabled(true, true, this);
    frequencySliderLFO.setTextValueSuffix(" hertz");
    frequencySliderLFO.setValue(1.0);
    frequencySliderLFO.addListener(this);


    resized();
}

CynthesisAudioProcessorEditor::~CynthesisAudioProcessorEditor()
{
}

//==============================================================================

void CynthesisAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    if (slider == &phaseSliderOsc1) {
        // TODO implement changes to osc1
        std::cout << "PLACEHOLDER osc1 phase: " << slider->getValue() << std::endl;
    }
    else if (slider == &semitonesSliderOsc1) {
        // TODO implement changes to osc1
        std::cout << "PLACEHOLDER osc1 semitones: " << slider->getValue() << std::endl;
    }
    else if (slider == &centsSliderOsc1) {
        // TODO implement changes to osc1
        std::cout << "PLACEHOLDER osc1 cents: " << slider->getValue() << std::endl;
    }
    else if (slider == &semitonesSliderOsc1) {
        // TODO implement changes to osc1
        std::cout << "PLACEHOLDER osc1 volume: " << slider->getValue() << std::endl;
    }
    else if (slider == &phaseSliderOsc2) {
        // TODO implement changes to osc2
        std::cout << "PLACEHOLDER osc2 phase: " << slider->getValue() << std::endl;
    }
    else if (slider == &semitonesSliderOsc2) {
        // TODO implement changes to osc2
        std::cout << "PLACEHOLDER osc2 semitones: " << slider->getValue() << std::endl;
    }
    else if (slider == &centsSliderOsc2) {
        // TODO implement changes to osc2
        std::cout << "PLACEHOLDER osc2 cents: " << slider->getValue() << std::endl;
    }
    else if (slider == &semitonesSliderOsc2) {
        // TODO implement changes to osc2
        std::cout << "PLACEHOLDER osc2 volume: " << slider->getValue() << std::endl;
    }
    else if (slider == &frequencySliderLFO) {
        // TODO implement changes to osc2
        std::cout << "PLACEHOLDER lfo frequency: " << slider->getValue() << std::endl;
    }
    else if (slider == &gainSlider) {
        processor.setGain(slider->getValue());
    }
}

void CynthesisAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

//    g.setColour (Colours::white);
//    g.setFont (16.0f);
//
//    g.drawFittedText ("Midi Volume by Cynthesis!", getLocalBounds(), Justification::centred, 1);
}

void CynthesisAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    int titleFontSize = (int) titleFont.getHeight();
    int headerFontSize = (int) headerFont.getHeight();
    int labelFontSize = (int) labelFont.getHeight();

    int textMargin = 10;
    int vertPadding = 30;
    int horizPadding = 30;
    int sliderHeight = getHeight() - 2*vertPadding - 2*textMargin - labelFontSize;
    int sliderWidth = 20;
    int rotarySpacing = 25;

    int rotaryKnobDiameter = 100;

    // coordinates used like a head. Changes should be relative not absolute in
    // most cases.
    int x = 0;
    int y = 0;
    // secondary head
    int xx;
    int yy;

    // temporary variables for intermediate computations
    int w, h;

    // titleLabel
    w = titleFont.getStringWidth(titleLabel.getText());
    h = titleFontSize;
    x = x + horizPadding;
    y = y + vertPadding;
    titleLabel.setBounds(x, y, w, h);


    //////////
    // Osc1 //
    //////////

    x = 0 + horizPadding + textMargin;
    y = y + titleFontSize + textMargin;

    // headerOsc1
    w = headerFont.getStringWidth(headerOsc1.getText());
    h = headerFontSize;
    headerOsc1.setBounds(x, y, w, h);

    x = x + textMargin;
    y = y + headerFontSize + textMargin + labelFontSize + textMargin;

    // phaseSliderOsc1
    w = h = rotaryKnobDiameter;
    phaseSliderOsc1.setBounds(x, y, w, h);
    // phaseLabelOsc1
    w = labelFont.getStringWidth(phaseLabelOsc1.getText());
    h = labelFontSize;
    xx = x + rotaryKnobDiameter/2 - w/2;
    yy = y - textMargin - labelFontSize;
    phaseLabelOsc1.setBounds(xx, yy, w, h);

    // semitonesSliderOsc1
    x = x + rotaryKnobDiameter + rotarySpacing;
    w = h = rotaryKnobDiameter;
    semitonesSliderOsc1.setBounds(x, y, w, h);
    // semitonesLabelOsc1
    w = labelFont.getStringWidth(semitonesLabelOsc1.getText());
    h = labelFontSize;
    xx = x + rotaryKnobDiameter/2 - w/2;
    yy = y - textMargin - labelFontSize;
    semitonesLabelOsc1.setBounds(xx, yy, w, h);

    // centsSliderOsc1
    x = x + rotaryKnobDiameter + rotarySpacing;
    w = h = rotaryKnobDiameter;
    centsSliderOsc1.setBounds(x, y, w, h);
    // centsLabelOsc1
    w = labelFont.getStringWidth(centsLabelOsc1.getText());
    h = labelFontSize;
    xx = x + rotaryKnobDiameter/2 - w/2;
    yy = y - textMargin - labelFontSize;
    centsLabelOsc1.setBounds(xx, yy, w, h);

    // volumeSliderOsc1
    x = x + rotaryKnobDiameter + rotarySpacing;
    w = h = rotaryKnobDiameter;
    volumeSliderOsc1.setBounds(x, y, w, h);
    // volumeLabelOsc1
    w = labelFont.getStringWidth(volumeLabelOsc1.getText());
    h = labelFontSize;
    xx = x + rotaryKnobDiameter/2 - w/2;
    yy = y - textMargin - labelFontSize;
    volumeLabelOsc1.setBounds(xx, yy, w, h);


    //////////
    // Osc2 //
    //////////

    x = 0 + horizPadding + textMargin;
    y = y + rotaryKnobDiameter + textMargin;

    // headerOsc2
    w = headerFont.getStringWidth(headerOsc2.getText());
    h = headerFontSize;
    headerOsc2.setBounds(x, y, w, h);

    x = x + textMargin;
    y = y + headerFontSize + textMargin + labelFontSize + textMargin;

    // phaseSliderOsc2
    w = h = rotaryKnobDiameter;
    phaseSliderOsc2.setBounds(x, y, w, h);
    // phaseLabelOsc2
    w = labelFont.getStringWidth(phaseLabelOsc2.getText());
    h = labelFontSize;
    xx = x + rotaryKnobDiameter/2 - w/2;
    yy = y - textMargin - labelFontSize;
    phaseLabelOsc2.setBounds(xx, yy, w, h);

    // semitonesSliderOsc2
    x = x + rotaryKnobDiameter + rotarySpacing;
    w = h = rotaryKnobDiameter;
    semitonesSliderOsc2.setBounds(x, y, w, h);
    // semitonesLabelOsc2
    w = labelFont.getStringWidth(semitonesLabelOsc2.getText());
    h = labelFontSize;
    xx = x + rotaryKnobDiameter/2 - w/2;
    yy = y - textMargin - labelFontSize;
    semitonesLabelOsc2.setBounds(xx, yy, w, h);

    // centsSliderOsc2
    x = x + rotaryKnobDiameter + rotarySpacing;
    w = h = rotaryKnobDiameter;
    centsSliderOsc2.setBounds(x, y, w, h);
    // centsLabelOsc2
    w = labelFont.getStringWidth(centsLabelOsc2.getText());
    h = labelFontSize;
    xx = x + rotaryKnobDiameter/2 - w/2;
    yy = y - textMargin - labelFontSize;
    centsLabelOsc2.setBounds(xx, yy, w, h);

    // volumeSliderOsc2
    x = x + rotaryKnobDiameter + rotarySpacing;
    w = h = rotaryKnobDiameter;
    volumeSliderOsc2.setBounds(x, y, w, h);
    // volumeLabelOsc2
    w = labelFont.getStringWidth(volumeLabelOsc2.getText());
    h = labelFontSize;
    xx = x + rotaryKnobDiameter/2 - w/2;
    yy = y - textMargin - labelFontSize;
    volumeLabelOsc2.setBounds(xx, yy, w, h);



    /////////
    // LFO //
    /////////

    x = 0 + horizPadding + textMargin;
    y = y + rotaryKnobDiameter + textMargin;

    // headerLFO
    w = headerFont.getStringWidth(headerLFO.getText());
    h = headerFontSize;
    headerLFO.setBounds(x, y, w, h);

    x = x + textMargin;
    y = y + headerFontSize + textMargin + labelFontSize + textMargin;

    // frequencySliderLFO
    w = h = rotaryKnobDiameter;
    frequencySliderLFO.setBounds(x, y, w, h);
    // frequencyLabelLFO
    w = labelFont.getStringWidth(frequencyLabelLFO.getText());
    h = labelFontSize;
    xx = x + rotaryKnobDiameter/2 - w/2;
    yy = y - textMargin - labelFontSize;
    frequencyLabelLFO.setBounds(xx, yy, w, h);


    // gainSlider
    x = getWidth() - horizPadding - sliderWidth;
    y = vertPadding + 2*textMargin + labelFontSize;
    gainSlider.setBounds(x, y, sliderWidth, sliderHeight);

    // gainLabel
//	gainLabel.attachToComponent(&gainSlider, false);
    w = labelFont.getStringWidth(gainLabel.getText());
    h = labelFontSize;
    x = gainSlider.getBounds().getCentreX() - w/2;
    y = gainSlider.getBounds().getY() - textMargin - labelFontSize;
    gainLabel.setBounds(x, y, w, h);
}
