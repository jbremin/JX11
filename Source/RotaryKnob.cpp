/*
  ==============================================================================

    RotaryKnob.cpp
    Created: 2 Jun 2024 10:37:18pm
    Author:  Johan Bremin

  ==============================================================================
*/

#include <JuceHeader.h>
#include "RotaryKnob.h"

//==============================================================================

static constexpr int labelHeight = 15;
static constexpr int textBoxHeight = 20;

RotaryKnob::RotaryKnob()
{
    slider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setRotaryParameters(juce::degreesToRadians(225.0f), juce::degreesToRadians(495.0f), true);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, textBoxHeight);
    addAndMakeVisible(slider);
    setBounds(0, 0, 100, 120);
}

RotaryKnob::~RotaryKnob()
{
}

void RotaryKnob::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setFont (15.0f);
    g.setColour (juce::Colours::white);
    
    auto bounds = getLocalBounds();
    g.drawText(label, juce::Rectangle<int> {0, 0, bounds.getWidth(), labelHeight}, juce::Justification::centred);
}

void RotaryKnob::resized()
{
    auto bounds = getLocalBounds();
    slider.setBounds(0, labelHeight, bounds.getWidth(), bounds.getHeight() - labelHeight);
}
