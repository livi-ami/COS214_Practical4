#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "Vehicle.h"
#include "Fleet.h"
#include "Ship.h"
#include "CargoHold.h"
#include "InsuranceCoverageDecorator.h"
#include "CustomClearanceDecorator.h"
#include "InspectionDecorator.h"
#include "FullFleetIterator.h"
#include "DelayedVehicleIterator.h"
#include "WaitingToLoadState.h"
#include "InTransitState.h"
#include "TransportDecorator.h"
#include "VehicleState.h"
#include "LoadedState.h"
#include "DelayedState.h"
#include "DeliveredState.h"

int main() {
    Fleet harbor("Main-Harbor Fleet");
    
    Ship* ship1 = new Ship("Vessel-Alpha-Deep");
    CargoHold* hold1A = new CargoHold("Hold-Alpha-1");
    CargoHold* hold1B = new CargoHold("Hold-Alpha-2");
    
    Ship* ship2 = new Ship("Vessel-Beta-Light");
    CargoHold* hold2A = new CargoHold("Hold-Beta-1");

    Vehicle* v1 = new Vehicle("V-CAR-01");
    Vehicle* v2 = new Vehicle("V-SUV-02");
    Vehicle* v3 = new Vehicle("V-SEMI-03");
    Vehicle* v4 = new Vehicle("V-VAN-04");
    Vehicle* v5 = new Vehicle("V-MOTO-05");

    std::cout << harbor.getId() << " " << ship1->getId() << " " << hold1A->getId() << "\n";

    WaitingToLoadState::instance()->arrive(*v1);
    WaitingToLoadState::instance()->depart(*v1);
    WaitingToLoadState::instance()->resume(*v1);

    WaitingToLoadState::instance()->load(*v1);
    WaitingToLoadState::instance()->load(*v2);
    WaitingToLoadState::instance()->load(*v3);
    WaitingToLoadState::instance()->load(*v4);
    WaitingToLoadState::instance()->load(*v5);

    TransportUnit* decV1 = new InsuranceCoverageDecorator(Insurance::INSURED, v1);
    decV1 = new CustomClearanceDecorator(STATUS::CLEARED, decV1);
    decV1 = new InspectionDecorator(Condition::GOOD, decV1);

    TransportUnit* decV2 = new InsuranceCoverageDecorator(Insurance::INSURED, v2);
    decV2 = new CustomClearanceDecorator(STATUS::CLEARED, decV2);
    decV2 = new InspectionDecorator(Condition::FAIR, decV2);

    TransportUnit* decV3 = new InsuranceCoverageDecorator(Insurance::NOT_INSURED, v3); 
    decV3 = new CustomClearanceDecorator(STATUS::PENDING, decV3);
    decV3 = new InspectionDecorator(Condition::GOOD, decV3);

    TransportUnit* decV4 = new InsuranceCoverageDecorator(Insurance::INSURED, v4);
    decV4 = new CustomClearanceDecorator(STATUS::CLEARED, decV4);
    decV4 = new InspectionDecorator(Condition::POOR, decV4); 

    TransportUnit* decV5 = new InsuranceCoverageDecorator(Insurance::INSURED, v5);
    decV5 = new CustomClearanceDecorator(STATUS::CLEARED, decV5);
    decV5 = new InspectionDecorator(Condition::GOOD, decV5);

    hold1A->addUnit(decV1);
    hold1A->addUnit(decV2);
    hold1B->addUnit(decV3);
    hold1B->addUnit(decV4);
    ship1->addUnit(hold1A);
    ship1->addUnit(hold1B);
    hold2A->addUnit(decV5);
    ship2->addUnit(hold2A);
    harbor.addUnit(ship1);
    harbor.addUnit(ship2);

    decV1->depart(*v1); 
    decV2->depart(*v2); 
    decV3->depart(*v3); 
    decV4->depart(*v4); 
    decV5->depart(*v5); 

    InTransitState::instance()->delay(*v2); 
    InTransitState::instance()->delay(*v5);

    if (v2->getState() != nullptr) {
        std::cout << v2->getState()->describe() << "\n";
    }
    
    VehicleState* v2State = v2->getState();
    if (v2State != nullptr) {
        v2State->resume(*v2);
    }

    InTransitState::instance()->arrive(*v1);
    if (v1->getState() != nullptr) {
        std::cout << v1->getState()->describe() << "\n";
        v1->getState()->load(*v1);
    }

    FullFleetIterator fullIt(harbor);
    while (fullIt.hasNext()) {
        TransportUnit* item = fullIt.next();
        if (item) {
            std::cout << " -> " << item->getStatus() << "\n";
        }
    }
    fullIt.next(); 

    DelayedVehicleIterator delayIt(harbor);
    while (delayIt.hasNext()) {
        TransportUnit* item = delayIt.next();
        if (item) {
            std::cout << " [DELAYED ASSET] " << item->getStatus() << "\n";
        }
    }
    delayIt.next();

    hold1A->getChildren().clear();
    hold1B->getChildren().clear();
    hold2A->getChildren().clear();

    delete decV1;
    delete decV2;
    delete decV3;
    delete decV4;
    delete decV5;

    return 0;
}
