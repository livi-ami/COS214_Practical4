#ifndef SHIP_H
#define SHIP_H
#include "TransportUnit.h"
#include <vector>
#include <string>
using namespace std;

class TransportUnit;

class Ship: public TransportUnit{
    private:
        friend class DelayedVehicleIterator;
        vector<TransportUnit*> cargoHold;
        string id;
    public:
        Ship(string id);
        ~Ship();
        Iterator* createIterator();
        void addUnit(TransportUnit* unit);
        void add(TransportUnit* child) override;//added this 
        void removeUnit(TransportUnit* unit);
        string getId();
        vector<TransportUnit*>& getChildren();
        VehicleState* getState() const override;
        void print() const override;
};

#endif