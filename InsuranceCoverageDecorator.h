#ifndef INSURANCECOVERAGEDECORATOR_H
#define INSURANCECOVERAGEDECORATOR_H

 using namespace std;

#include "TransportDecorator.h"
#include <string>

enum class Insurance{
    INSURED,
    NOT_INSURED
   
};


class InsuranceCoverageDecorator : public TransportDecorator {
private:
   Insurance currentInsurance; 

    public:
    InsuranceCoverageDecorator(Insurance insurance_,TransportUnit* child);
  
    std::string getStatus() override; 
    void depart(TransportUnit& unit) override;
};

#endif