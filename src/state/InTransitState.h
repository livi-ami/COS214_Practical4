#ifndef INTRANSITSTATE_H
#define INTRANSITSTATE_H

#include "VehicleState.h"

class InTransitState : public VehicleState {
public:
    static InTransitState* instance();

    void arrive(Vehicle& vehicle) override;
    void delay(Vehicle& vehicle) override;

    std::string getName() const override { return "In Transit"; }
    std::string describe() const override;

private:
    InTransitState() = default;
};

#endif