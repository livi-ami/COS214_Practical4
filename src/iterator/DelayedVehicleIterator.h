#ifndef DELAYED_VEHICLE_ITERATOR_H
#define DELAUED_VEHICLE_ITERATOR_H
#include "Iterator.h"
#include <vector>
using namespace std;

class DelayedVehicleIterator: public Iterator{
    private:
        vector<TransportUnit*> snapshot;
        size_t curPos;
    public:
        DelayedVehicleIterator(const TransportUnit& units);
        virtual TransportUnit* next();
        virtual bool hasNext() const;
};

#endif