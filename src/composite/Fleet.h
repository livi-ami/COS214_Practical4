#ifndef FLEET_H
#define FLEET_H
#include "TransportUnit.h"
#include <vector>
#include <string>
using namespace std;

class VehicleState;
class Iterator;

class Fleet: public TransportUnit{
    private:
        friend class FullFleetIterator;
        //friend class DelayedVehicleIterator;
        vector<TransportUnit*> ships;
        string id;
    public:
        Fleet(string id);
        ~Fleet();
        Iterator* createIterator();
        void addUnit(TransportUnit* unit);
        void removeUnit(TransportUnit* unit);
        string getId();
        vector<TransportUnit*>& getChildren();
};

#endif