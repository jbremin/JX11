/*
  ==============================================================================

    LookAndFeel.h
    Created: 3 Jun 2024 11:00:37pm
    Author:  Johan Bremin

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class LookAndFeel : public juce::LookAndFeel_V4
{
public:
    LookAndFeel();
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LookAndFeel)
};
