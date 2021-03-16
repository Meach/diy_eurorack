#include "channel_output.h"

//--------------------------------------------------------------
void ChannelOutput::setup(int pinDac, int pinGate, int pinLed) {
    
    // Save the pins
    _pinDac = pinDac;
    _pinGate = pinGate;
    _pinLed = pinLed;
    _state = false;


    // DAC - Pitch & Velocity
    _dac = new MCP4822(_pinDac);

    _dac->init();

    // The channels are turned off at startup so we need to turn the channel we need on
    _dac->turnOnChannelA();
    _dac->turnOnChannelB();
    
    // We configure the channels in High gain
    // It is also the default value so it is not really needed
    _dac->setGainA(MCP4822::High);
    _dac->setGainB(MCP4822::High);
    

    // Gate    
    pinModeFast(_pinGate, OUTPUT);
    digitalWriteFast(_pinGate, LOW);

    // LED
    pinModeFast(_pinLed, OUTPUT);
    digitalWriteFast(_pinLed, LOW);
    

    _doUpdate = false;
}

//--------------------------------------------------------------
void ChannelOutput::update() {
    if(_doUpdate) {
        _dac->updateDAC();
        digitalWriteFast(_pinGate, _state);
        digitalWriteFast(_pinLed, _state);

        _doUpdate = false;
    }
}

//--------------------------------------------------------------
void ChannelOutput::setNoteOn(byte note, byte velocity) {

    // Map velocity 0-127 -> 0-4Vdc
    int vel = map(velocity, 0, 127, 0, 4000);

    // Get note value
    int pitch = g_notes[note];

    // Serial.println("Output: pitch=" + String(pitch) + ", vel=" + String(vel));

    _dac->setVoltageA(pitch);
    _dac->setVoltageB(vel);
    // digitalWriteFast(_pinGate, HIGH);
    // digitalWriteFast(_pinLed, HIGH);

    _state = true;
    _doUpdate = true;
}

//--------------------------------------------------------------
void ChannelOutput::setNoteOff(byte note, byte velocity) {
    // Map velocity 0-127 -> 0-4Vdc
    int vel = map(velocity, 0, 127, 0, 4000);

    // Get note value
    int pitch = g_notes[note];

    _dac->setVoltageA(pitch);
    _dac->setVoltageB(vel);
    // digitalWriteFast(_pinGate, LOW);
    // digitalWriteFast(_pinLed, LOW);
    
    _state = false;
    _doUpdate = true;
}