#ifndef WAITINGTOLOADSTATE_H
#define WAITINGTOLOADSTATE_H

#include "VehicleState.h"

// initial state
class WaitingToLoadState : public VehicleState {
public:
    static WaitingToLoadState* instance();

    void load(Vehicle& vehicle) override;
    void delay(Vehicle& vehicle) override;

    std::string getName() const override { return "Waiting To Load"; }
    std::string describe() const override;

private:
    WaitingToLoadState() = default; // singleton: construct only via instance()
};

#endif