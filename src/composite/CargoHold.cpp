#include "CargoHold.h"
#include "../iterator/DelayedVehicleIterator.h"
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