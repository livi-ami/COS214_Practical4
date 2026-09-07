#include "TransportDecorator.h"

  TransportDecorator::TransportDecorator(TransportUnit* unit):wrapped(unit){}
  
    TransportDecorator::~TransportDecorator() {
        delete wrapped;
    }

    void  TransportDecorator::add(TransportUnit* child){
         if (wrapped != 0)
    {
        wrapped->add(child);
    }
    }

    VehicleState* TransportDecorator::getState() const {
        return wrapped->getState();
    }

    void TransportDecorator::addUnit(TransportUnit* unit) {
        wrapped->addUnit(unit);
    }

    std::vector<TransportUnit*>& TransportDecorator::getChildren() {
        return wrapped->getChildren();
    }


 void TransportDecorator::depart(TransportUnit& unit) {
    if (wrapped != nullptr) {
        wrapped->depart(unit); 
    }
}

std::string TransportDecorator::getStatus() {
    if (wrapped != nullptr) {
        return wrapped->getStatus();
    }
    return "";
}
