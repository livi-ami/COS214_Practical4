# COS214_Practical4


//Composite


//Iterator




//State



//DECORATOR
The TransportDecorator delegates the TransportUnit operations defined in its interface to the wrapper variable which can be any of the transport unit so that the wrapper as its full functionality while being decorated.

The deleted copy constructor and assignment operator prevent copies of the decorator because it owns the wrapped object. Copying could cause multiple decorators to delete the same wrapper.

The are 3 decorators that our system uses namely InspectionDecoator where the TransportUnits are each examined and inspected if they are then they are marked off based on their condition either goood,fair or poor and the other decorator is the InsuaranceCoverage stating if a unit is insured or not and the CustomClearanceDecorator currently displays a supplied status from the client. 
