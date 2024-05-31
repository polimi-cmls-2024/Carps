#pragma once
#include <JuceHeader.h>

class Distortion
{
public:
    Distortion();
    void prepare(const juce::dsp::ProcessSpec& spec);
    void process(juce::dsp::ProcessContextReplacing<float> context);
    void setDistortionAmount(float amount);

private:
    float distortionAmount;

    enum
    {
        preGainIndex,
        waveshaperIndex,
        postGainIndex
    };

    juce::dsp::ProcessorChain<juce::dsp::Gain<float>,
                              juce::dsp::WaveShaper<float>,
                              juce::dsp::Gain<float>> processorChain;
};