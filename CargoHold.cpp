#include "CargoHold.h"
#include "DelayedVehicleIterator.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

CargoHold::CargoHold(string id):id(id){}

CargoHold::~CargoHold(){
    for(size_t i=0; i<vehicles.size(); ++i){
        delete vehicles[i];
    }
}

Iterator* CargoHold::createIterator(){
    return new DelayedVehicleIterator(*this);
}

void CargoHold::addUnit(TransportUnit* unit){
    if(unit==nullptr){
        cout<<"Cannot add null unit"<<endl;
        return;
    }
    vehicles.push_back(unit);
}

/*void CargoHold::removeUnit(TransportUnit* unit){

}*/

string CargoHold::getId(){
    return id;
}

vector<TransportUnit*>& CargoHold::getChildren(){
    return vehicles;
}


void CargoHold::depart(TransportUnit& unit) {
    for (auto child : getChildren()) {
        if (child != nullptr) {
            child->depart(unit); // Cascades down until it finally hits the Vehicles!
        }
    }
}
std::string CargoHold::getStatus() {
    return "CargoHold [" + id + "]";
}