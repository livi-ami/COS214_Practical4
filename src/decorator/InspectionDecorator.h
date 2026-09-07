#ifndef INSPECTIONDECORATOR_H
#define INSPECTIONDECORATOR_H




 using namespace std;

#include "TransportDecorator.h"
#include <string>

enum class condition{
    GOOD,
    FAIR,
    POOR
};


class InspectionDecorator : public TransportDecorator {
private:
string condition;

    public:
    InspectionDecorator(std::string condition_,TransportUnit* child);
    void print() const override;


};



#endif