#include "InsuranceCoverageDecorator.h"
#include <iostream>

InsuranceCoverageDecorator::InsuranceCoverageDecorator(Insurance insurance_, TransportUnit* child)
    : TransportDecorator(child) {
    currentInsurance = insurance_;
}



void InsuranceCoverageDecorator::depart(TransportUnit& unit) {
    if (currentInsurance == Insurance::INSURED) {
        std::cout << "[Insurance] Unit is insured. Passing departure down.\n";
        TransportDecorator::depart(unit);
    } else {
        std::cout << "[Insurance Hold] Cannot depart. Unit is uninsured!\n";
    }
}

std::string InsuranceCoverageDecorator::getStatus() {
    switch (currentInsurance) {
        case Insurance::INSURED:     return "INSURED";
        case Insurance::NOT_INSURED: return "NOT_INSURED";
        default:                     return "UNKNOWN";
    }
}
