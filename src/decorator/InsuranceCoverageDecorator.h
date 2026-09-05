#ifndef INSURANCECOVERAGEDECORATOR_H
#define INSURANCECOVERAGEDECORATOR_H

 using namespace std;

#include "TransportDecorator.h"
#include <string>

enum class insurance{
    INSURED,
    NOT_INSURED
   
};


class InsuranceCoverageDecorator : public TransportDecorator {
private:
string insurance;

    public:
    InsuranceCoverageDecorator(string insurance_,TransportUnit* child);
    void print()const override ;
};

#endif