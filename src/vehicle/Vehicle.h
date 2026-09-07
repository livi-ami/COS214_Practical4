#ifndef VEHICLE_H
#define VEHICLE_H

#include "../composite/TransportUnit.h"
#include "../state/VehicleState.h"
#include <string>

class Vehicle : public TransportUnit {
public:
    explicit Vehicle(const std::string& id);
    ~Vehicle() override;

    // State delegation
    void load();
    void depart();
    void arrive();
    void delay();
    void resume();

    std::string getStatus() const;  //current state's short name
    std::string report() const;     //longer state-dependent description

    //called subclasses to switch the vehicle's current state
    void setState(VehicleState* newState);

    std::string getId() const override { return id; }

private:
    std::string id;
    VehicleState* currentState;
};

#endif
