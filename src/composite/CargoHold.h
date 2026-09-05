#ifndef CARGO_HOLD_H
#define CARGO_HOLD_H
#include "TransportUnit.h"
#include <vector>
#include <string>
using namespace std;

class Iterator;

class CargoHold: public TransportUnit{
    private:
        friend class FullFleetIterator;
        //friend class DelayedVehicleIterator;
        vector<TransportUnit*> vehicles;
        string id;
    public:
        CargoHold(string id);
        ~CargoHold();
        Iterator* createIterator();
        void addUnit(TransportUnit* unit);
        void removeUnit(TransportUnit* unit);
        string getId();
        vector<TransportUnit*>& getChildren();
        void print() const override;
};

#endif