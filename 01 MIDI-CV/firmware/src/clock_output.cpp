#include "clock_output.h"

//--------------------------------------------------------------
void ClockOutput::setup(int pinClock, int pinLed) {
    _pinClock = pinClock;
    _state = false;
    _cnt = 0;
    _timeref = 0;
    pinModeFast(_pinClock, OUTPUT);

    _pinLed = pinLed;
    pinModeFast(_pinLed, OUTPUT);

    setClock(false);

    _doUpdate = false;
}

//--------------------------------------------------------------
void ClockOutput::update() {
    if(_doUpdate) {
        setClock(_state);
        _doUpdate = false;
    }

    // Pull the clock state low if it was high
    if(_state) {
        if(millis() - _timeref > 20) {
            setClock(false);
        };
    }
}

// Clock events are sent at a rate of 24 pulses per quarter note
//--------------------------------------------------------------
void ClockOutput::tick() {
    if(_cnt == 0) {
        // Save time and set the clock signal high
        _timeref = millis();

        _state = true;
        _doUpdate = true;
    }

    // Increment the counter
    _cnt++;
    if(_cnt == 24) {
        _cnt = 0;
    }
}

//--------------------------------------------------------------
void ClockOutput::reset() {
    _cnt = 0;
}

//--------------------------------------------------------------
void ClockOutput::setClock(bool state) {
    _state = state;
    digitalWriteFast(_pinClock, _state);
    digitalWriteFast(_pinLed, _state);
}