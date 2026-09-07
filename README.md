# COS214_Practical4


//Composite
The Composite pattern represents individual transport units and groups of transport units using the same TransportUnit interface. A Vehicle acts as a leaf, while a Ship, CargoHold, or Fleet can act as a composite containing other transport units.

This allows clients to treat a single vehicle and a group of transport units uniformly. Composite objects manage their children using operations such as addUnit() and getChildren(), while each concrete class provides its own print() behavior.

For example, a Fleet can contain Ships, a Ship can contain CargoHolds, and a CargoHold can contain Vehicles. This creates a hierarchy of transport units without requiring the client to handle each type separately.

//Iterator

The Iterator pattern provides a consistent way to traverse transport units without exposing how their children are stored. A Fleet, Ship, or CargoHold can create an iterator that visits its transport units in the required order.

The client uses the iterator operations to check whether more transport units are available and to retrieve the next unit. This keeps traversal logic separate from the composite classes and allows different traversal strategies, such as traversing a complete fleet or only delayed vehicles.


//state

The State pattern manages the lifecycle of a transport vehicle. A vehicle can be in different states, including WaitingToLoad, Loaded, InTransit, Delayed, and Delivered. Each state defines which actions are valid and controls the transition to the next state.

For example, a vehicle starts in the WaitingToLoad state. After it is loaded, it changes to Loaded and can then depart into the InTransit state. When it arrives, it changes to Delivered. If a problem occurs during loading or transit, the vehicle changes to Delayed and must resume before continuing.

This allows the vehicle's behavior to change according to its current state without using large conditional statements in the Vehicle class.



//DECORATOR
The TransportDecorator delegates the TransportUnit operations defined in its interface to the wrapper variable which can be any of the transport unit so that the wrapper has its full functionality while being decorated.

The deleted copy constructor and assignment operator prevent copies of the decorator because it owns the wrapped object. Copying could cause multiple decorators to delete the same wrapper.


The are 3 decorators that our system uses namely InspectionDecoator where the TransportUnits are each examined and inspected if they are then they are marked off based on their condition either goood,fair or poor and the other decorator is the InsuaranceCoverage stating if a unit is insured or not and the CustomClearanceDecorator currently displays a supplied status from the client.

//How it all works together
# COS214_Practical4   

## Dockerfile   

### Instructions to run Dockerfile   

docker build -t taskforge-img .   
docker rm taskforgeApp   
docker run --name taskforgeApp taskforge-img
