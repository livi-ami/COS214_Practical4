#include "Fleet.h"
#include "FullFleetIterator.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

Fleet::Fleet(std::string id):id(id){}

Fleet::~Fleet(){
    for(size_t i=0; i<ships.size(); ++i){
        delete ships[i];
    }
}

Iterator* Fleet::createIterator(){
    return new FullFleetIterator(*this);
}

void Fleet::addUnit(TransportUnit* unit){
    if(unit==nullptr){
        cout<<"Cannot add null unit"<<endl;
        return;
    }
    ships.push_back(unit);
}

/*void Fleet::removeUnit(TransportUnit* unit){

}*/

string Fleet::getId(){
    return id;
}

vector<TransportUnit*>& Fleet::getChildren(){
    return ships;
}

void Fleet::depart(TransportUnit& unit) {
    for (auto child : ships) { // Loops through its internal vector
        if (child != nullptr) {
            child->depart(unit);
        }
    }
}
std::string Fleet::getStatus() {
    return "Fleet [" + id + "]";
}