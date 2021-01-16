/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ShakhGainAudioProcessorEditor::ShakhGainAudioProcessorEditor (ShakhGainAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    gainSlider.setRange(-60.0f, 0.0f, 0.01f);
    gainSlider.setValue(-20.5f);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

ShakhGainAudioProcessorEditor::~ShakhGainAudioProcessorEditor()
{
}

//==============================================================================
void ShakhGainAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
}

void ShakhGainAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 100, 100, 200);
}

void ShakhGainAudioProcessorEditor::sliderValueChanged(juce::Slider* slider) 
{
    if (slider == &gainSlider) 
    {
       audioProcessor.gain = gainSlider.getValue();
    }
}