/*
  ==============================================================================

    LookAndFeel.cpp
    Created: 3 Jun 2024 11:00:37pm
    Author:  Johan Bremin

  ==============================================================================
*/

#include "LookAndFeel.h"

LookAndFeel::LookAndFeel()
{
    setColour(juce::ResizableWindow::backgroundColourId, juce::Colour(30, 60, 90));
    
    setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colour(0, 0, 0));
    setColour(juce::Slider::rotarySliderFillColourId, juce::Colour(90, 180, 240));
    setColour(juce::Slider::thumbColourId, juce::Colour(255, 255, 255));
}
