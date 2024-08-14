/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
JX11AudioProcessorEditor::JX11AudioProcessorEditor (JX11AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    outputLevelKnob.label = "Level";
    addAndMakeVisible(outputLevelKnob);
    
    filterResoKnob.label = "Reso";
    addAndMakeVisible(filterResoKnob);
    
    polyModeButton.setButtonText("Poly");
    polyModeButton.setClickingTogglesState(true);
    addAndMakeVisible(polyModeButton);
    
    midiLearnButton.setButtonText("MIDI Learn");
    midiLearnButton.addListener(this);
    addAndMakeVisible(midiLearnButton);
    
    setSize (600, 400);
    juce::LookAndFeel::setDefaultLookAndFeel(&globalLNF);
}

JX11AudioProcessorEditor::~JX11AudioProcessorEditor()
{
    midiLearnButton.removeListener(this);
}

//==============================================================================
void JX11AudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void JX11AudioProcessorEditor::resized()
{
    juce::Rectangle r(20, 20, 100, 120);
    outputLevelKnob.setBounds(r);
    
    r = r.withX(r.getRight() + 20);
    filterResoKnob.setBounds(r);
    
    polyModeButton.setSize(80, 30);
    polyModeButton.setCentrePosition(r.withX(r.getRight()).getCentre());
    
    midiLearnButton.setBounds(400, 20, 100, 30);
}

void JX11AudioProcessorEditor::buttonClicked(juce::Button* button)
{
    button->setButtonText("Waiting...");
    button->setEnabled(false);
    audioProcessor.midiLearn = true;
}
