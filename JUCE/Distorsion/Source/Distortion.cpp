#include "Distortion.h"

Distortion::Distortion()
    : distortionAmount(0.5f)
{
    auto& waveshaper = processorChain.template get<1>();
    waveshaper.functionToUse = [](float x)
    {
        return std::tanh(x);
    };

    auto& preGainProc = processorChain.template get<0>();
    preGainProc.setGainDecibels(30.0f);

    auto& postGainProc = processorChain.template get<2>();
    postGainProc.setGainDecibels(-20.0f);
}

void Distortion::prepare(const juce::dsp::ProcessSpec& spec)
{
    processorChain.prepare(spec);
}

void Distortion::process(juce::dsp::ProcessContextReplacing<float> context)
{
    processorChain.process(context);
}

void Distortion::setDistortionAmount(float amount)
{
    distortionAmount = amount;
}
