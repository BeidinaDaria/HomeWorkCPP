#pragma once
#include "State.h"

class Process {
private:
    State* state;
    void setState(State* newState) {
        state = newState;
    }

    void getState();
public:
    Process() : state(nullptr) {}
    void livecycle();
};

