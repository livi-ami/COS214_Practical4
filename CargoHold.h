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
        std::vector<TransportUnit*> vehicles;
        std::string id;
    public:
        CargoHold(string id);
        ~CargoHold();
        Iterator* createIterator();
        void addUnit(TransportUnit* unit);
        void removeUnit(TransportUnit* unit);
        std::string getId();
        std::vector<TransportUnit*>& getChildren();
        
        void depart(TransportUnit& unit) override;
        std::string getStatus() override; 

};

#endif