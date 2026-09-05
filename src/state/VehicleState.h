#ifndef VEHICLESTATE_H
#define VEHICLESTATE_H
 
#include <string>
 
class Vehicle;

class VehicleState {
public:
    virtual ~VehicleState() = default;
 
    virtual void load(Vehicle& vehicle);
    virtual void depart(Vehicle& vehicle);
    virtual void arrive(Vehicle& vehicle);
    virtual void delay(Vehicle& vehicle);
    virtual void resume(Vehicle& vehicle);
 
    virtual std::string getName() const = 0;
    virtual std::string describe() const = 0;

    virtual bool isTemporary() const { return false; }
 
protected:
    void reject(Vehicle& vehicle, const std::string& action) const;
};
 
#endif