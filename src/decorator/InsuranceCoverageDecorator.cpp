#include "InsuranceCoverageDecorator.h"



#include <iostream>

InsuranceCoverageDecorator::InsuranceCoverageDecorator(string insurance_,TransportUnit* child):TransportDecorator(child){
    insurance=insurance_;
}
    void InsuranceCoverageDecorator::print() const{
           TransportDecorator::print();
    cout << "Insurance status: " << insurance<< endl;
}
    