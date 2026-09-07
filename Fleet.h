#ifndef FLEET_H
#define FLEET_H
#include "TransportUnit.h"
#include <vector>
#include <string>


class VehicleState;
class Iterator;

class Fleet: public TransportUnit{
    private:
        friend class FullFleetIterator;
        //friend class DelayedVehicleIterator;
        std::vector<TransportUnit*> ships;
        std::string id;
    public:
        Fleet(std::string id);
        ~Fleet();
        Iterator* createIterator();
        void addUnit(TransportUnit* unit);
        void removeUnit(TransportUnit* unit);
        std::string getId();
        std::vector<TransportUnit*>& getChildren();
       
        void depart(TransportUnit& unit) override;
        std::string getStatus() override; 
        
};

#endif