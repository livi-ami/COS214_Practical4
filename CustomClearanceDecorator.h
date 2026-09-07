#ifndef CUSTOMCLEARANCEDECORATOR_H
#define CUSTOMCLEARANCEDECORATOR_H



#include "TransportDecorator.h"
#include <string>

enum class STATUS{
    CLEARED,
    PENDING
};


class CustomClearanceDecorator: public TransportDecorator{
private:
STATUS currentStatus; 

    public:
    CustomClearanceDecorator(STATUS status_,TransportUnit* child);
  
    void setCustomsStatus(STATUS newStatus);
    void depart(TransportUnit& unit) override ;
    std::string getStatus() override ;
};






#endif