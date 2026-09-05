#ifndef TRANSPORT_UNIT_H
#define TRANSPORT_UNIT_H
#include <vector>

class VehicleState;

class TransportUnit{
    public:
        virtual ~TransportUnit();
        virtual VehicleState* getState() const = 0;
        virtual void addUnit(TransportUnit* unit) = 0;
        virtual vector<TransportUnit*>& getChildren() = 0;
};

#endif