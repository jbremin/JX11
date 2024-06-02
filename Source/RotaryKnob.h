/*
  ==============================================================================

    RotaryKnob.h
    Created: 2 Jun 2024 10:37:18pm
    Author:  Johan Bremin

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class RotaryKnob  : public juce::Component
{
public:
    RotaryKnob();
    ~RotaryKnob() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    juce::Slider slider;
    juce::String label;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RotaryKnob)
};
