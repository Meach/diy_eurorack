#pragma once

#include <Arduino.h>
#include <MCP48xx.h>
#include <digitalWriteFast.h>

#include "notes.h"

class ChannelOutput {
public:
    void setup(int pinDac, int pinGate, int pinLed);
    void update();

    void setNoteOn(byte note, byte velocity);
    void setNoteOff(byte note, byte velocity);

private:
    int _pinDac;
    int _pinGate;
    int _pinLed;
    bool _state;

    MCP4822 *_dac;

    bool _doUpdate;
};
