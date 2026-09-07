#ifndef TRANSPORTDECORATOR_H
#define TRANSPORTDECORATOR_H

#include "TransportUnit.h"

class Vehicle;
class TransportDecorator:public TransportUnit{
 
    protected:
    TransportUnit* wrapped;

    public:
    TransportDecorator(TransportUnit* unit);
    ~TransportDecorator() override;
    TransportDecorator(const TransportDecorator&) = delete;
    TransportDecorator& operator=(const TransportDecorator&) = delete;
    void add(TransportUnit* child);
   

     //functions from the TransportUnit
     VehicleState* getState() const override;
     void addUnit(TransportUnit* unit) override;
     std::vector<TransportUnit*>& getChildren() override;
       void depart(TransportUnit& unit) override;
     std::string getStatus() override;


};




#endif