#ifndef LOADEDSTATE_H
#define LOADEDSTATE_H

#include "VehicleState.h"

class LoadedState : public VehicleState {
public:
    static LoadedState* instance();

    void depart(Vehicle& vehicle) override;

    std::string getName() const override { return "Loaded"; }
    std::string describe() const override;

private:
    LoadedState() = default;
};

#endif