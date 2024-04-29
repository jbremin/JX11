/*
  ==============================================================================

    Synth.h
    Created: 7 Jan 2024 6:29:36pm
    Author:  Johan Bremin

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Voice.h"
#include "NoiseGenerator.h"

class Synth
{
public:
    Synth();
        
    void allocateResources(double sampleRate, int samplesPerBlock);
    void deallocateResources();
    void reset();
    void render(float** outputBuffers, int sampleCount);
    void midiMessage(uint8_t data0, uint8_t data1, uint8_t data2);
    void controlChange(uint8_t data1, uint8_t data2);
    
    static constexpr int MAX_VOICES = 8;
    int numVoices;
    
    float noiseMix;
    float detune;
    float tune;
    float envAttack;
    float envDecay;
    float envSustain;
    float envRelease;
    float oscMix;
    float volumeTrim;
    float vibrato;
    float filterKeyTracking;
    float filterQ;
    float filterLFODepth;
    
    float velocitySensitivity;
    bool ignoreVelocity;
    
    juce::LinearSmoothedValue<float> outputLevelSmoother;
    
    const int LFO_MAX = 32;
    float lfoInc;
    
    float pwmDepth;
    int glideMode;
    float glideRate;
    float glideBend;
        
private:
    
    inline void updatePeriod(Voice& voice)
    {
        voice.osc1.period = voice.period * pitchBend;
        voice.osc2.period = voice.osc1.period * detune;
    }
    
    bool isPlayingLegatoStyle() const;
    
    void noteOn(int note, int velocity);
    void noteOff(int note);
    float calcPeriod(int v, int note) const;
    void startVoice(int v, int note, int velocity);
    void restartMonoVoice(int note, int velocity);
    void shiftQueuedNotes();
    int nextQueuedNote();
    void updateLFO();
    
    int findFreeVoice() const;
    bool sustainPedalPressed;
    float sampleRate;
    
    std::array<Voice, MAX_VOICES> voices;
    NoiseGenerator noiseGen;
    float filterCtl;
    float pitchBend;
    float modWheel;
    
    int lfoStep;
    float lfo;
    int lastNote;
    
    float resonanceCtl;
    float pressure;
    float filterZip;
};
