#ifndef TRANSPORTDECORATOR_H
#define TRANSPORTDECORATOR_H

#include "../composite/TransportUnit.h"


class TransportDecorator:public TransportUnit{
 
    protected:
    TransportUnit* wrapped;

    public:
    TransportDecorator(TransportUnit* unit);
    ~TransportDecorator() override;
    TransportDecorator(const TransportDecorator&) = delete;
    TransportDecorator& operator=(const TransportDecorator&) = delete;
    void add(TransportUnit* child);
     void print() const = 0;

     //functions from the TransportUnit
     VehicleState* getState() const override;
     void addUnit(TransportUnit* unit) override;
     std::vector<TransportUnit*>& getChildren() override;



};




#endif