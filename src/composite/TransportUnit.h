#ifndef TRANSPORT_UNIT_H
#define TRANSPORT_UNIT_H
#include <vector>


class VehicleState;

class TransportUnit{
    public:
        virtual ~TransportUnit();
        virtual VehicleState* getState() const = 0;
        virtual void addUnit(TransportUnit* unit) = 0;
        virtual std::vector<TransportUnit*>& getChildren() = 0;

        virtual void add(TransportUnit* child) = 0;
        virtual void print() const = 0;
};

#endif