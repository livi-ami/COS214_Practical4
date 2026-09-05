#ifndef DELIVEREDSTATE_H
#define DELIVEREDSTATE_H

#include "VehicleState.h"

//terminal state
class DeliveredState : public VehicleState {
public:
    static DeliveredState* instance();

    std::string getName() const override { return "Delivered"; }
    std::string describe() const override;

private:
    DeliveredState() = default;
};

#endif