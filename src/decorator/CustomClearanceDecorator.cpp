#include "CustomClearanceDecorator.h"
#include <iostream>

CustomClearanceDecorator::CustomClearanceDecorator(std::string status_,TransportUnit* child):TransportDecorator(child){
    status=status_;
}
    void CustomClearanceDecorator::print() const{
           TransportDecorator::print();
    std::cout << "Clearance status: " << status<< std::endl;
}
    