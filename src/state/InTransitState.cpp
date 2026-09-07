#include "InTransitState.h" 
#include "DeliveredState.h"
#include "DelayedState.h"
#include "../vehicle/Vehicle.h"
#include <iostream>

InTransitState* InTransitState::instance() {
    static InTransitState singleton;
    return &singleton;
}
 
void InTransitState::arrive(Vehicle& vehicle) {
    std::cout << "Vehicle " << vehicle.getId() << " has arrived and is now delivered.\n";
    vehicle.setState(DeliveredState::instance());
}
 
void InTransitState::delay(Vehicle& vehicle) {
    std::cout << "Vehicle " << vehicle.getId() << " delayed while in transit.\n";
    vehicle.setState(new DelayedState(this));
}
 
std::string InTransitState::describe() const {
    return "en route to its destination";
}