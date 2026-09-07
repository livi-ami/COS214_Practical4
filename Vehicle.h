#ifndef VEHICLE_H
#define VEHICLE_H
#include "TransportUnit.h"
#include <string>
#include <vector>
using namespace std;

class VehicleState;

class Vehicle : public TransportUnit {
protected:
    Vehicle();
private:
    VehicleState* state;
    std::string id;
public:
    Vehicle(std::string id);
    ~Vehicle();
    void addUnit(TransportUnit* unit) override;
    void add(TransportUnit* unit) override;
    std::vector<TransportUnit*>& getChildren() override;
    VehicleState* getState() const override;
    void setState(VehicleState* state);
    std::string getId();
    
    void depart(TransportUnit& unit) override;
    std::string getStatus() override;
};
#endif