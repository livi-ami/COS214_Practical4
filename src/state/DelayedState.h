#ifndef DELAYEDSTATE_H
#define DELAYEDSTATE_H
 
#include "VehicleState.h"

//NOT a singleton
class DelayedState : public VehicleState {
public:
    explicit DelayedState(VehicleState* previousState);
 
    void resume(Vehicle& vehicle) override;
 
    std::string getName() const override { return "Delayed"; }
    std::string describe() const override;
 
    bool isTemporary() const override { return true; }
 
private:
    VehicleState* previousState;
};
 
#endif
 


