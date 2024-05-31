#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
class DistortionAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    DistortionAudioProcessorEditor (DistortionAudioProcessor&);
    ~DistortionAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    DistortionAudioProcessor& audioProcessor;

    juce::Slider distortionSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> distortionSliderAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DistortionAudioProcessorEditor)
};