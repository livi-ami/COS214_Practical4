#include "composite/Ship.h"
#include "decorator/InspectionDecorator.h"
#include "decorator/InsuranceCoverageDecorator.h"

int main() {
    TransportUnit* transport = new Ship("Ship-1");

    transport = new InspectionDecorator("GOOD", transport);
    transport = new InsuranceCoverageDecorator("INSURED", transport);

    transport->print();  // normal system behavior

    delete transport;
}