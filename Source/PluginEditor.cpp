#include "PluginEditor.h"
#include "PluginProcessor.h"

//==============================================================================
WaveFolderProcessorEditor::WaveFolderProcessorEditor (WaveFolderProcessor& p)
    : AudioProcessorEditor (&p), 
      processorRef (p), 
      mKeyboardComponent(mKeyBoardState, juce::MidiKeyboardComponent::horizontalKeyboard)
{
    juce::ignoreUnused (processorRef);
    addAndMakeVisible(mKeyboardComponent);
    setSize(1280, 720);
}

WaveFolderProcessorEditor::~WaveFolderProcessorEditor()
{

}

//==============================================================================
void WaveFolderProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void WaveFolderProcessorEditor::resized()
{
    auto area = getLocalBounds();
    
    juce::Rectangle<int> componentBounds;
    componentBounds.setBounds(100, 100, 100, 100);
    mKeyboardComponent.setBounds(area.removeFromBottom(80).reduced(8));
}
