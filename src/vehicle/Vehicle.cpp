#include "Vehicle.h"
#include "VehicleState.h"
#include <string>
#include <iostream>
using namespace std;

Vehicle::Vehicle(){
    id = "ERROR";
    state = nullptr;
}

Vehicle::Vehicle(string id):id(id){
    //state = new <someDefaultState> idk what it is - Rei 
}

Vehicle::~Vehicle(){
    delete state;
}

void Vehicle::addUnit(TransportUnit* unit){
    cout<<"Cannot add to "<<id<<" since it is a vehicle"<<endl;
}

VehicleState* Vehicle::getState(){
    return state;
}

void Vehicle::setState(VehicleState* state){
    delete state;
    this->state = state;
}

string Vehicle::getId(){
    return id;
}