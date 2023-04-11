#pragma once

#include "PluginProcessor.h"

//==============================================================================
class WaveFolderProcessorEditor : public juce::AudioProcessorEditor {
public:
    explicit WaveFolderProcessorEditor (WaveFolderProcessor&);
    ~WaveFolderProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    WaveFolderProcessor& processorRef;

    // Keyboard
    juce::MidiKeyboardState mKeyBoardState;
    juce::MidiKeyboardComponent mKeyboardComponent;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveFolderProcessorEditor)
};
