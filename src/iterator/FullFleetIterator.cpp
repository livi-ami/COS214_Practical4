#include "FullFleetIterator.h"
#include "TransportUnit.h"
#include "Fleet.h"
#include "Ship.h"
#include "CargoHold.h"
#include <vector>



FullFleetIterator::FullFleetIterator(const TransportUnit& fleet_){
    curPos=0;
    snapshot=fleet_.getChildren();
}
void FullFleetIterator::createSnapshot(TransportUnit* unit){
        if (unit == nullptr) {
                return;
        }
       snpshot.push_back(unit);
       if (auto fleet = dynamic_cast<Fleet*>(unit)) {
        for (auto child : fleet->getChildren()) { 
            createSnapshot(child); 
        }
    } 
    else if (auto ship = dynamic_cast<Ship*>(unit)) {
        for (auto child : ship->getChildren()) {
            createSnapshot(child); 
        }
    }

}
TransportUnit* FullFleetIterator::next(){
    if(!hasNext()){
        return nullptr;
    }
    return snapshot[curPos++];
}

bool FullFleetIterator::hasNext() const{
    return curPos < snapshot.size();
}