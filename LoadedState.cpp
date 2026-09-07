#include "LoadedState.h"
#include "InTransitState.h"
#include "Vehicle.h"
#include <iostream>

LoadedState* LoadedState::instance() {
    static LoadedState singleton;
    return &singleton;
}

void LoadedState::depart(Vehicle& vehicle) {
    std::cout << "Vehicle " << vehicle.getId() << " is departing and is now in transit.\n";
    vehicle.setState(InTransitState::instance());
}

std::string LoadedState::describe() const {
    return "loaded into a cargo hold, ready to depart";
}