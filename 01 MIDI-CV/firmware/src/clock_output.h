#pragma once

#include <Arduino.h>
#include <digitalWriteFast.h>

class ClockOutput {
public:
    void setup(int pinClock, int pinLed);
    void update();

    void tick();
    void reset();

private:
    int _pinClock;
    int _pinLed;
    bool _state;

    int _cnt;
    unsigned long _timeref;
    void setClock(bool state);

    bool _doUpdate;
};