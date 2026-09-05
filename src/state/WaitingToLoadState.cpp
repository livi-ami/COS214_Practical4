#include "WaitingToLoadState.h"
#include "LoadedState.h"
#include "DelayedState.h"
#include "../vehicle/Vehicle.h"
#include <iostream>

WaitingToLoadState* WaitingToLoadState::instance() {
    static WaitingToLoadState singleton;
    return &singleton;
}

void WaitingToLoadState::load(Vehicle& vehicle) {
    std::cout << "Vehicle " << vehicle.getId() << " is loaded into its cargo hold.\n";
    vehicle.setState(LoadedState::instance());
}

void WaitingToLoadState::delay(Vehicle& vehicle) {
    std::cout << "Vehicle " << vehicle.getId() << " delayed while waiting to load.\n";
    vehicle.setState(new DelayedState(this));
}

std::string WaitingToLoadState::describe() const {
    return "sitting, awaiting loading";
}