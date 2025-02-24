cmake_minimum_required(VERSION 3.28)
project(M1OEP_wteegard)

set(CMAKE_CXX_STANDARD 14)

set(JUCE_PATH "midi/JUCE")

add_subdirectory(${JUCE_PATH})

add_executable(M1OEP_wteegard
        main.cpp
        Key.cpp
        Chord.cpp
        Track.cpp
        Measure.cpp
        ChordBank.cpp
        Triad.cpp)

target_link_libraries(M1OEP_wteegard PRIVATE juce::juce_core juce::juce_audio_basics)

add_executable(Test
        Testing.cpp
        Key.cpp
        Chord.cpp
        Track.cpp
        Measure.cpp
        ChordBank.cpp
        Triad.cpp)

target_link_libraries(Test PRIVATE juce::juce_core juce::juce_audio_basics)