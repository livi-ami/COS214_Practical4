#include "CustomClearanceDecorator.h"
#include <iostream>

CustomClearanceDecorator::CustomClearanceDecorator(STATUS status_, TransportUnit* child)
    : TransportDecorator(child) {
    currentStatus = status_;
}


void CustomClearanceDecorator::setCustomsStatus(STATUS newStatus) {
    currentStatus = newStatus;
}

void CustomClearanceDecorator::depart(TransportUnit& unit) {
    if (currentStatus == STATUS::CLEARED) {
        std::cout << "[Customs] Status is 'CLEARED'. Passing departure down.\n";
        TransportDecorator::depart(unit);
    } else {
        std::cout << "[Customs Blocked] Cannot depart. Status is currently: PENDING\n";
    }
}

std::string CustomClearanceDecorator::getStatus() {
    switch (currentStatus) {
        case STATUS::CLEARED: return "CLEARED";
        case STATUS::PENDING: return "PENDING";
        default:              return "UNKNOWN";
    }
}
