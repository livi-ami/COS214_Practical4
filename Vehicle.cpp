#include "Vehicle.h"
#include "VehicleState.h"
#include "WaitingToLoadState.h"
#include <string>
#include <iostream>
using namespace std;

Vehicle::Vehicle(){
    id = "ERROR";
    state = WaitingToLoadState::instance();
}

Vehicle::Vehicle(string id):id(id){
    state = WaitingToLoadState::instance();
}

Vehicle::~Vehicle(){
}

void Vehicle::addUnit(TransportUnit* unit){
    cout<<"Cannot add to "<<id<<" since it is a vehicle"<<endl;
}

void Vehicle::add(TransportUnit* unit){
    addUnit(unit);
}

vector<TransportUnit*>& Vehicle::getChildren(){
    static vector<TransportUnit*> noChildren;
    return noChildren;
}

VehicleState* Vehicle::getState() const{
    return state;
}

void Vehicle::setState(VehicleState* state){
    this->state = state;
}

string Vehicle::getId(){
    return id;
}

void Vehicle::depart(TransportUnit& unit) {
    if (state) {
        state->depart(*this); 
    }
}
std::string Vehicle::getStatus() {
    if (state != nullptr) {
        return "Vehicle " + id + " [" + state->getName() + "]";
    }
    return "Vehicle " + id + " [No State]";
}