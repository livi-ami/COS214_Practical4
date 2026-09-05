#ifndef DELIVEREDSTATE_H
#define DELIVEREDSTATE_H

#include "VehicleState.h"

// Terminal state. Deliberately overrides nothing beyond getName()/describe(),
// so every action (load/depart/arrive/delay/resume) falls through to the
// base class and is rejected - a delivered vehicle's lifecycle is over.
class DeliveredState : public VehicleState {
public:
    static DeliveredState* instance();

    std::string getName() const override { return "Delivered"; }
    std::string describe() const override;

private:
    DeliveredState() = default;
};

#endif