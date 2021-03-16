#pragma once

#include <Arduino.h>
#include "channel_output.h"
#include "clock_output.h"

class Outputs {

public:
    void setup();
    void update();

    void setNoteOn(byte channel, byte note, byte velocity);
    void setNoteOff(byte channel, byte note, byte velocity);

    // Clock
    void updateClock();
    void resetClock();

private:
    // Pitch / Velocity outputs
    ChannelOutput _channels[2];

    // Clock
    ClockOutput _clock;
};
