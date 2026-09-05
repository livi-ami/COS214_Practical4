#include "DelayedState.h"
#include "../vehicle/Vehicle.h"
#include <iostream>
 
DelayedState::DelayedState(VehicleState* previousState)
    : previousState(previousState) {}
 
void DelayedState::resume(Vehicle& vehicle) {
    std::cout << "Vehicle " << vehicle.getId() << " resumes from delay, returning to "
              << previousState->getName() << ".\n";
    VehicleState* target = previousState;
    vehicle.setState(target);
    delete this;
}
 
std::string DelayedState::describe() const {
    return "held up (e.g. weather or congestion), waiting to resume from "
           + previousState->getName();
}