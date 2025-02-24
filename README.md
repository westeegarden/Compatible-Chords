# Wesley Teegarden M1OEP
## Compatible Chords 
Compatable chords is a music notation software that serves as a tool to help musicians
write music. Music theory is a complex subject, and it can be difficult to keep track
of all the rules and math behind it. With compatible chords, musicians can leave
the calculations to the computer and focus on composing.
  
## The program
The goal of the program is to create a "track", which is effectively a chord progression. On startup,
the user is prompted to input the key signature they wish to work in, after which a chord bank is
generated containing (almost) every chord that fits within that key. At this point, the user is continuously
presented with a menu of options where they can start building their track, view the chord bank for
reference, change keys for a new set of chords, export their track as a MIDI file, or exit the program.

## Module 2 Concepts
#### Inheritence Class Relationship
1. Chord/Triad - In this program there are two types of chords: Triads (which contain 3 notes) and Seventh
chords (which contain 4 notes). To work with this I created the Triad class, which is a child class of Chord
with the necessary methods overwritten to account for the different number of notes.

#### Component Class Relationship
1. ChordBank/Chord - ChordBank objects contain a vector of Chord/Triad objects.
2. Measure/Chord - Measure objects contain a vector of Chord/Triad objects.
3. Track/Measure - Track objects contain a vector of Measure objects.

#### File I/O
The final form of a track in Compatable Chords is a MIDI file. A MIDI file is a binary file that
tells electronic instruments what notes to play and when. Think of a MIDI file as the little
drum with braille-like bumps that turns in a music box. After the user has named and exported their file,
they can load it into a digital audio workstation (DAW) to hear their track played back.

## JUCE Framework
In order to export MIDI files, I needed the help of the JUCE framework. JUCE is a C++ framework
that is designed for creating audio applications. I utilized the midi submodule in Track::exportMidiFile()
to properly format the outgoing MIDI file. I have the JUCE GitHub repository linked in the midi/
directory of this project.

## My Grade
This project should recieve 150+ points. The program is more than complex enough with extenzive 
input validation. My testing program is also very thourough and effectively tests all applicable
methods. I included 4 "is a/has a" relationships that are a crucial part of the program. Finally, 
I went above and beyond with my file I/O by exporting MIDI files instead of .txt files. This feature
required much additional research and comsumed most of my time spent on this project. 

## Next Steps
Going forward, I would like to impliment a GUI and make the workflow of the executable less linear.
By this I mean I would like to allow the user to go back and edit their track at any point.
```
