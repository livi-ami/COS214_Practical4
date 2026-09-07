#include "InspectionDecorator.h"
#include <iostream>

InspectionDecorator::InspectionDecorator(std::string condition_,TransportUnit* child):TransportDecorator(child){
    condition=condition_;
}
    void InspectionDecorator::print() const{
           TransportDecorator::print();
    cout << "Inspection condition: " << condition<< endl;
}
    