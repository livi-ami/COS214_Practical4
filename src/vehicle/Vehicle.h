#ifndef VEHICLE_H
#define VEHICLE_H
#include "../composite/TransportUnit.h"
#include <string>
using namespace std;

class VehicleState;

class Vehicle: public TransportUnit{
    protected:
        Vehicle();
    private:
        VehicleState* state;
        string id;
    public:
        Vehicle(string id);
        ~Vehicle();
        void addUnit(TransportUnit* unit);
        VehicleState* getState();
        void setState(VehicleState* state);
        string getId();
        void print() const;
};

#endif