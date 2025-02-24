

#include "Track.h"
#include <iostream>
using namespace std;

Track::Track() = default;

/*
 * addMeasure
 * Requires: ostream, istream, ChordBank
 * Modifies: measures vector
 * Returns: nothing
 * Adds a measure to the track
 */ 
void Track::addMeasure(ostream &outs, istream &ins, ChordBank& currentChordBank) {
    //Creating measure and filling it with chords
    Measure m(4);
    m.fillMeasure(outs, ins, currentChordBank);
    measures.push_back(m);
}

bool Track::isTrackStarted() {
    return trackStarted;
}

void Track::printTrack(ostream &outs) {
    outs << endl << "Your Track:" << endl;  
    for (auto & measure : measures) {
        measure.printMeasure(outs);
        outs << endl;
    }
}


/*
 * exportMidiFile
 * Requires: juce::File
 * Modifies: nothing
 * Returns: nothing
 * Exports the track to a MIDI file
 */
void Track::exportMidiFile(const juce::File& outputFile) {
    juce::MidiMessageSequence midiSequence;

    // Timing resolution
    int ticksPerBeat = 960;
	int ticksPerMeasure = ticksPerBeat * 4;

    // Current time in ticks for the MIDI sequence
    double startTime = 0.0;
	double currentTime = 0.0;

	// Loop through each measure in the track
    for (int i = 0; i < measures.size(); i++) {
        bool holdChord = false;
        Chord currentChord;

		// Loop through each chord in the measure
        for (int j = 0; j < measures[i].getChords().size(); j++) {

            //Update timestamp
            currentTime = startTime + (i * ticksPerMeasure) + (j * ticksPerBeat);

            if (!holdChord) {
                //Assign current chord
                currentChord = measures[i].getChords()[j];

                // Loop through each note in the chord to add NoteOn events
                for (int k = 0; k < currentChord.getNotes().size(); k++) {

                    int notePosition = currentChord.getNotes()[k] + 56; //Setting note values to midi format (C4 = 60)

                    // Add note on event (note start)
                    juce::MidiMessage noteOn(juce::MidiMessage::noteOn(1, notePosition, (juce::uint8)100)); // Channel 1, velocity 100
                    noteOn.setTimeStamp(currentTime);
                    midiSequence.addEvent(noteOn);
                }
            }

            //Check if next index contains an empty chord
			if (j + 1 < measures[i].getChords().size()) {
				if (measures[i].getChords()[j + 1].getNotes().empty()) {
					holdChord = true;
				}
				else {
					holdChord = false;
				}
			}
			else {
				holdChord = false;
			}

            // Loop through each note in the chord to add NoteOff events
			if (!holdChord) {
				for (int k = 0; k < currentChord.getNotes().size(); k++) {

                    int notePosition = currentChord.getNotes()[k] + 56; //Setting note values to midi format (C4 = 60)

					// Add note off event (note stop)
					juce::MidiMessage noteOff(juce::MidiMessage::noteOff(1, notePosition));
					noteOff.setTimeStamp(currentTime + ticksPerBeat);
					midiSequence.addEvent(noteOff);
				}
			}
		}
	}

    // Write the midi sequence to a file
    juce::FileOutputStream outputStream(outputFile);
    if (outputStream.openedOk())
    {
        juce::MidiFile midiFile;
        midiFile.clear();
        midiFile.setTicksPerQuarterNote(ticksPerBeat);
        midiFile.addTrack(midiSequence);
        midiFile.writeTo(outputStream);

        cout << "MIDI file exported to: " << outputFile.getFullPathName() << endl;
    }
    else
    {
        cout << "Failed to open file for writing!" << endl;
    }
}


