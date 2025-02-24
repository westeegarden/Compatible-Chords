#ifndef TRACK_H
#define TRACK_H

#include <string>
#include <vector>
#include <iostream>
#include "Measure.h"
#include <juce_audio_basics/juce_audio_basics.h> 

using namespace std;

/*--------Track Class Header--------*/

class Track {
private:
    vector<Measure> measures;
    bool trackStarted = false;

public:
    Track();

    void addMeasure(ostream &outs, istream &ins, ChordBank& currentChordBank);

    bool isTrackStarted();

    void printTrack(ostream& outs);

    void exportMidiFile(const juce::File& outputFile);
};

#endif //TRACK_H
