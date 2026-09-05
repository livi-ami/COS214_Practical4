#ifndef TRANSPORT_UNIT_H
#define TRANSPORT_UNIT_H

class VehicleState;

class TransportUnit{
    public:
        TransportUnit();
        virtual ~TransportUnit();
        virtual VehicleState* getState() const = 0;
        virtual void addUnit(TransportUnit* unit) = 0;
};

#endif