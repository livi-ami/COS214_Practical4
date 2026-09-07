#include "InspectionDecorator.h"
#include <iostream>

InspectionDecorator::InspectionDecorator(Condition condition_,TransportUnit* child):TransportDecorator(child){
    currentCondition=condition_;
}

void InspectionDecorator::depart(TransportUnit& unit) {
    if (currentCondition == Condition::GOOD || currentCondition == Condition::FAIR) {
        std::cout << "[Inspection] Condition cleared. Passing departure down.\n";
        TransportDecorator::depart(unit); 
    } else {
     
        std::cout << "[Safety Hold] Cannot depart. Vehicle inspection status is: " << getStatus() << "\n";
    }
}
std::string InspectionDecorator::getStatus() {
    switch(currentCondition) {
        case Condition::GOOD: return "GOOD";
        case Condition::FAIR: return "FAIR";
        case Condition::POOR: return "POOR";
        default:              return "UNKNOWN";
    }
}