#include "WaveFolderVoice.h"

WaveFolderVoice::WaveFolderVoice() {
    auto& osc = mProcessorChain.template get<oscillator>();
    auto& shaper = mProcessorChain.template get<waveShaper>();
    
    osc.initialise ([] (float x) { return std::sin (x); }, 128);
    shaper.functionToUse = [] (float x) {
        return tanh(x) + sin(x * (2.f * juce::MathConstants<float>::pi));
    };
}

bool WaveFolderVoice::canPlaySound(juce::SynthesiserSound* leadSound) {
    return dynamic_cast<WaveFolderVoice*> (leadSound) != nullptr;
}

void WaveFolderVoice::startNote (
    int midiNoteNumber,
    float velocity,
    juce::SynthesiserSound *sound,
    int currentPitchWheelPosition
) {
    DBG(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
    setFrequency(midiNoteNumber);
}

void WaveFolderVoice::stopNote(float velocity, bool allowTailOff) {

}

void WaveFolderVoice::prepareVoice(double sampleRate, int samplesPerBlock, int numOutputChannels) {

}

void WaveFolderVoice::prepareSpec(double sampleRate, int samplesPerBlock, int numOutputChannels) {
    mSpec.sampleRate = sampleRate;
    mSpec.maximumBlockSize = samplesPerBlock;
    mSpec.numChannels = numOutputChannels;
    mProcessorChain.prepare(mSpec);
}

void WaveFolderVoice::renderNextBlock(
    juce::AudioBuffer<float>& outputBuffer,
    int startSample,
    int numSamples
) {
    auto block = juce::dsp::AudioBlock<float>(outputBuffer);
    juce::dsp::ProcessContextReplacing<float> context(block);
    mProcessorChain.process(context);
}

void WaveFolderVoice::pitchWheelMoved(int newPitchWheelValue) {
    
}

void WaveFolderVoice::controllerMoved(int controllerNumber, int newControllerValue) {
    
}

void WaveFolderVoice::setFrequency(float newValue, bool force)  {
    auto& osc = mProcessorChain.template get<oscillator>();
    osc.setFrequency (newValue, force);
}

void WaveFolderVoice::setLevel(float newValue) {
    auto& gainLevel = mProcessorChain.template get<gain>();
    gainLevel.setGainLinear (newValue);
}