#ifndef INSPECTIONDECORATOR_H
#define INSPECTIONDECORATOR_H




 using namespace std;

#include "TransportDecorator.h"
#include <string>

enum class Condition {
    GOOD,
    FAIR,
    POOR
};


class InspectionDecorator : public TransportDecorator {
private:
Condition currentCondition;

    public:
    InspectionDecorator(Condition  condition_,TransportUnit* child);
  
    void depart(TransportUnit& unit)override;
    std::string getStatus() override; 
};



#endif