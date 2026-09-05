#ifndef DELAYEDSTATE_H
#define DELAYEDSTATE_H
 
#include "VehicleState.h"
 
//NOT a singleton: two different
// vehicles could be delayed at the same time from two different origin
// states (one waiting to load, one in transit), and each needs to remember
// its own origin so resume() sends it back to the right place.
//
// Ownership: a DelayedState instance is created with `new` by whichever
// state's delay() was called, and it deletes itself (`delete this`) inside
// resume() once it has handed the vehicle back to its previous state.
// The previous state itself is always one of the shared singletons, so it
// is never deleted here.
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
 


