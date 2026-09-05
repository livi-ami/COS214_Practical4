#ifndef CUSTOMCLEARANCEDECORATOR_H
#define CUSTOMCLEARANCEDECORATOR_H



#include "TransportDecorator.h"
#include <string>

enum class status{
    CLEARED,
    PENDING
};


class CustomClearanceDecorator: public TransportDecorator{
private:
std::string status;

    public:
    CustomClearanceDecorator(std::string status_,TransportUnit* child);
    void print() const override;

};






#endif