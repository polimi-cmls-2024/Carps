#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DistortionAudioProcessorEditor::DistortionAudioProcessorEditor (DistortionAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    distortionSlider.setSliderStyle(juce::Slider::Rotary);
    distortionSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(distortionSlider);

    distortionSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.getParameters(), "distortion", distortionSlider);

    setSize (400, 300);
}

DistortionAudioProcessorEditor::~DistortionAudioProcessorEditor()
{
}

void DistortionAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Distortion Plugin", getLocalBounds(), juce::Justification::centred, 1);
}

void DistortionAudioProcessorEditor::resized()
{
    distortionSlider.setBounds(getLocalBounds().reduced(40));
}