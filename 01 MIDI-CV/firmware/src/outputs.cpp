#include "outputs.h"

//--------------------------------------------------------------
void Outputs::setup() {
    _channels[0].setup(10, A0, A2);
    _channels[1].setup(9, A1, A3);
    
    _clock.setup(A5, A4);
}

//--------------------------------------------------------------
void Outputs::update() {
    _channels[0].update();
    _channels[1].update();
    _clock.update();
}

//--------------------------------------------------------------
void Outputs::setNoteOn(byte channel, byte note, byte velocity) {
    _channels[channel].setNoteOn(note, velocity);
}

//--------------------------------------------------------------
void Outputs::setNoteOff(byte channel, byte note, byte velocity) {
    _channels[channel].setNoteOff(note, velocity);
}

//--------------------------------------------------------------
void Outputs::updateClock() {
    _clock.tick();
}

//--------------------------------------------------------------
void Outputs::resetClock() {
    _clock.reset();
}