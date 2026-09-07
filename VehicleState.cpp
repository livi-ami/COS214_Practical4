#include "VehicleState.h"
#include "Vehicle.h"
#include <iostream>

void VehicleState::load(Vehicle& vehicle)   { reject(vehicle, "load"); }
void VehicleState::depart(Vehicle& vehicle) { reject(vehicle, "depart"); }
void VehicleState::arrive(Vehicle& vehicle) { reject(vehicle, "arrive"); }
void VehicleState::delay(Vehicle& vehicle)  { reject(vehicle, "delay"); }
void VehicleState::resume(Vehicle& vehicle) { reject(vehicle, "resume"); }
 
void VehicleState::reject(Vehicle& vehicle, const std::string& action) const {
    std::cout << "[Invalid Action] Vehicle " << vehicle.getId()
              << " cannot '" << action << "' while " << getName() << ".\n";
}