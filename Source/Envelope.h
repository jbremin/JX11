/*
  ==============================================================================

    Envelope.h
    Created: 25 Feb 2024 4:57:57pm
    Author:  Johan Bremin

  ==============================================================================
*/

#pragma once

const float SILENCE = 0.0001f;

class Envelope
{
public:
    void reset()
    {
        level = 0.0f;
        target = 0.0f;
        multiplier = 0.0f;
    }
    
    float nextValue()
    {
        level = multiplier * (level - target) + target;
        
        if (level + target > 3.0f) {
            multiplier = decayMultiplier;
            target = sustainLevel;
        }
        
        return level;
    }
    
    inline bool isInAttack() const
    {
        return target >= 2.0f;
    }
    
    void attack()
    {
        level += SILENCE + SILENCE;
        target = 2.0f;
        multiplier = attackMultiplier;
    }
    
    void release()
    {
        target = 0.0f;
        multiplier = releaseMultiplier;
    }
    
    inline bool isActive() const
    {
        return level > SILENCE;
    }
    
    float level;
    
    float attackMultiplier;
    float decayMultiplier;
    float sustainLevel;
    float releaseMultiplier;
    
private:
    
    float multiplier;
    float target;
};
