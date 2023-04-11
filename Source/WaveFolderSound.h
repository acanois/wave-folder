#pragma once

class WaveFolderSound  : public SynthesiserSound {
    bool appliesToNote (int midiNoteNumber) override { return true; }
    bool appliesToChannel (int midiChannel) override { return true; }
};