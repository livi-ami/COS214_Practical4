
#include "DelayedVehicleIterator.h"
#include "TransportUnit.h"
#include "Fleet.h"
#include "Ship.h"
#include "CargoHold.h"
#include "Vehicle.h"
#include "VehicleState.h"
#include <vector>



DelayedVehicleIterator::DelayedVehicleIterator(TransportUnit& units){
    curPos=0;
    for (auto child : units.getChildren()) {
        extractDelayedVehicles(child);
    }
}


void DelayedVehicleIterator::extractDelayedVehicles(TransportUnit* unit) {
    if (unit == nullptr) return;

    if (auto fleet = dynamic_cast<Fleet*>(unit)) {
        for (auto child : fleet->getChildren()) { 
            extractDelayedVehicles(child); 
        }
    } 
    else if (auto ship = dynamic_cast<Ship*>(unit)) {
        for (auto child : ship->getChildren()) {
            extractDelayedVehicles(child); 
        }
    } 
    else if (auto cargoHold = dynamic_cast<CargoHold*>(unit)) {
        for (auto child : cargoHold->getChildren()) {
            extractDelayedVehicles(child);
        }
    }
    else {

        if (auto vehicle = dynamic_cast<Vehicle*>(unit)) {
       
        if (vehicle->getState() != nullptr && vehicle->getState()->getName() == "Delayed") {
            snapshot.push_back(unit); 
            }
        }
    }
}


TransportUnit* DelayedVehicleIterator::next(){
    if(!hasNext()){
     return nullptr;
    }
    return snapshot[curPos++];
 }
bool DelayedVehicleIterator::hasNext() const{
      return curPos < snapshot.size();
  }