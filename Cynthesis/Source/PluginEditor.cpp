<<<<<<< HEAD:Cynthesis_01/Source/PluginEditor.cpp
/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Cynthesis_01AudioProcessorEditor::Cynthesis_01AudioProcessorEditor (Cynthesis_01AudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    //setSize (400, 283);
    setSize (600, 600);
}

Cynthesis_01AudioProcessorEditor::~Cynthesis_01AudioProcessorEditor()
{
}

//==============================================================================
void Cynthesis_01AudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("This is a Cynthesis Plugin!", getLocalBounds(), Justification::centred, 1);
}

void Cynthesis_01AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
=======
/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

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
    setSize (400, 300);
}

CynthesisAudioProcessorEditor::~CynthesisAudioProcessorEditor()
{
}

//==============================================================================
void CynthesisAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void CynthesisAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
>>>>>>> 518d4f6ec64d20f8061b4b05fafc164f5727061d:Cynthesis/Source/PluginEditor.cpp
