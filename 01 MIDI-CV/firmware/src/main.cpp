#include <Arduino.h>
#include <MIDI.h>

#include "outputs.h"


// MIDI instance and callbacks
MIDI_CREATE_DEFAULT_INSTANCE();

void handleNoteOff(byte channel, byte note, byte velocity);
void handleNoteOn(byte channel, byte note, byte velocity);
void handleClock(void);
void handleStart(void);
void handleStop(void);

//
Outputs outputs;

//--------------------------------------------------------------
void setup() {
    // Launch MIDI and listen to channel 0
    MIDI.begin(0);
    // Set callbacks for messages we are interested in
    MIDI.setHandleNoteOn(handleNoteOn);
    MIDI.setHandleNoteOff(handleNoteOff);
    MIDI.setHandleClock(handleClock);
    MIDI.setHandleStart(handleStart);
    MIDI.setHandleStop(handleStop);
    
    outputs.setup();
}

//--------------------------------------------------------------
void loop() {
    MIDI.read();
    outputs.update();
}


//--------------------------------------------------------------
// MIDI callbacks
//--------------------------------------------------------------

//--------------------------------------------------------------
void handleNoteOff(byte channel, byte note, byte velocity) {
    
    // Only deal with channel 1 & 2, notes from 36 to 132
    if (channel == 1 || channel == 2) {
        if (note >= 36 && note <= 132) {
            outputs.setNoteOff(channel - 1, note - 36, velocity);
        }
    }
}

//--------------------------------------------------------------
void handleNoteOn(byte channel, byte note, byte velocity) {
    
    // Only deal with channel 1 & 2, notes from 36 to 132
    if (channel == 1 || channel == 2) {
        if (note >= 36 && note <= 132) {
            outputs.setNoteOn(channel - 1, note - 36, velocity);
        }
    }
}

//--------------------------------------------------------------
void handleClock(void) {    
    outputs.updateClock();
}

//--------------------------------------------------------------
void handleStart(void) {
    outputs.resetClock();
}

//--------------------------------------------------------------
void handleStop(void) {
    outputs.resetClock();
}