#ifndef ITERATOR_H
#define ITERATOR_H

class TransportUnit;

class Iterator{
    public:
        virtual ~Iterator();
        virtual TransportUnit* next() = 0;
        virtual bool hasNext() const = 0;
};

#endif