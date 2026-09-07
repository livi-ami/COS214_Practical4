#ifndef TRANSPORT_UNIT_H
#define TRANSPORT_UNIT_H

#include <vector>
#include <string>

class VehicleState;

class TransportUnit {
public:
    virtual ~TransportUnit() = default;
  

    virtual VehicleState* getState() const { return nullptr; }
    
    virtual void add(TransportUnit*) {}
    virtual void addUnit(TransportUnit*) {}
    virtual void depart(TransportUnit&) {} 

    virtual std::string getStatus() { return "Transport Unit"; }
    
    virtual std::vector<TransportUnit*>& getChildren() = 0;
};

#endif
