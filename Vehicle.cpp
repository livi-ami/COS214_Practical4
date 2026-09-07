#include "Vehicle.h"
#include "../state/WaitingToLoadState.h"

Vehicle::Vehicle(const std::string& id)
    : id(id), currentState(WaitingToLoadState::instance()) {}

Vehicle::~Vehicle() {
    if (currentState->isTemporary()) {
        delete currentState;
    }
}

void Vehicle::load()   { currentState->load(*this); }
void Vehicle::depart() { currentState->depart(*this); }
void Vehicle::arrive() { currentState->arrive(*this); }
void Vehicle::delay()  { currentState->delay(*this); }
void Vehicle::resume() { currentState->resume(*this); }

std::string Vehicle::getStatus() const { return currentState->getName(); }

std::string Vehicle::report() const {
    return "Vehicle " + id + " is " + currentState->describe();
}

void Vehicle::setState(VehicleState* newState) {
    currentState = newState;
}