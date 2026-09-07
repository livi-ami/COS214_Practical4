#ifndef VEHICLE_H
#define VEHICLE_H

#include "../composite/TransportUnit.h"
#include "../state/VehicleState.h"
#include <string>

class Vehicle : public TransportUnit {
public:
    explicit Vehicle(const std::string& id);
    ~Vehicle() override;

    void load();
    void depart();
    void arrive();
    void delay();
    void resume();

    std::string getStatus() const;
    std::string report() const;

    void setState(VehicleState* newState);

    std::string getId() const override { return id; }

private:
    std::string id;
    VehicleState* currentState;
};

#endif