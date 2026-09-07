#ifndef SHIP_H
#define SHIP_H
#include "TransportUnit.h"
#include <vector>
#include <string>
using namespace std;

class TransportUnit;
class Iterator;

class Ship: public TransportUnit{
    private:
        friend class DelayedVehicleIterator;
        std::vector<TransportUnit*> cargoHold;
        std::string id;
    public:
        Ship(string id);
        ~Ship();
        Iterator* createIterator();
        void addUnit(TransportUnit* unit);
        void add(TransportUnit* child) override;//added this 
        void removeUnit(TransportUnit* unit);
        std::string getId();
        std::vector<TransportUnit*>& getChildren();
        VehicleState* getState() const override;
    
        void depart(TransportUnit& unit) override;
        std::string getStatus() override; 

};

#endif