#ifndef FULL_FLEET_ITERATOR
#define FULL_FLEET_ITERATOR
#include "Iterator.h"
#include <vector>
using namespace std;

class Fleet;

class FullFleetIterator: public Iterator{
    private:
        vector<TransportUnit*> snapshot;
        size_t curPos;
        void createSnapshot(TransportUnit* unit);
    public:
        FullFleetIterator(const TransportUnit& fleet_);
        virtual TransportUnit* next();
        virtual bool hasNext() const;
};

#endif