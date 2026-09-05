#include "Ship.h"
#include "../iterator/DelayedVehicleIterator.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

Ship::Ship(string id):id(id){}

Ship::~Ship(){
    for(size_t i=0; i<cargoHold.size(); ++i){
        delete cargoHold[i];
    }
}

Iterator* Ship::createIterator(){
    return new DelayedVehicleIterator(*this);
}

void Ship::addUnit(TransportUnit* unit){
    if(unit==nullptr){
        cout<<"Cannot add null unit"<<endl;
        return;
    }
    cargoHold.push_back(unit);
}

void Ship::add(TransportUnit* child){
    addUnit(child);
}

VehicleState* Ship::getState() const{
    return nullptr;
}

/*void Ship::removeUnit(TransportUnit* unit){

}*/

string Ship::getId(){
    return id;
}

vector<TransportUnit*>& Ship::getChildren(){
    return cargoHold;
}
void Ship::print() const {
    cout << "Ship: " << id << endl;
}