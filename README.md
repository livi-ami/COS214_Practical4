# COS214 Practical 4 — TaskForge

TaskForge is a hierarchical work-processing system for a sea and inland vehicle transport domain. A **Fleet** contains **Ships**, each **Ship** contains **CargoHolds**, and each **CargoHold** carries individual **Vehicles**. The system makes meaningful use of four Gang of Four patterns — **Composite** (the nested Fleet/Ship/CargoHold/Vehicle hierarchy), **Iterator** (traversing that hierarchy without exposing its internals), **State** (each Vehicle's lifecycle), and **Decorator** (optional runtime handling requirements on a Vehicle) — combined into a single coherent system rather than four separate demos.

A hierarchical work-processing system built around four core design patterns: **Composite**, **Iterator**, **State**, and **Decorator**.

## Table of Contents
- [Composite](#composite)
- [Iterator](#iterator)
- [State](#state)
- [Decorator](#decorator)
- [Building the Project](#building-the-project)
- [Running with Docker](#running-with-docker)
- [Team](#team)

---

## Composite

The Composite pattern represents individual transport units and groups of transport units using the same `TransportUnit` interface. A `Vehicle` acts as a leaf, while a `Ship`, `CargoHold`, or `Fleet` can act as a composite containing other transport units.

This allows clients to treat a single vehicle and a group of transport units uniformly. Composite objects manage their children using operations such as `addUnit()` and `getChildren()`, while each concrete class provides its own `print()` behavior.

For example, a `Fleet` can contain `Ship`s, a `Ship` can contain `CargoHold`s, and a `CargoHold` can contain `Vehicle`s. This creates a hierarchy of transport units without requiring the client to handle each type separately.

## Iterator

The Iterator pattern provides a consistent way to traverse transport units without exposing how their children are stored. A `Fleet`, `Ship`, or `CargoHold` can create an iterator that visits its transport units in the required order.

The client uses the iterator operations to check whether more transport units are available and to retrieve the next unit. This keeps traversal logic separate from the composite classes and allows different traversal strategies, such as traversing a complete fleet or only delayed vehicles.

## State

The State pattern manages the lifecycle of a transport vehicle. A vehicle can be in different states, including `WaitingToLoad`, `Loaded`, `InTransit`, `Delayed`, and `Delivered`. Each state defines which actions are valid and controls the transition to the next state.

For example, a vehicle starts in the `WaitingToLoad` state. After it is loaded, it changes to `Loaded` and can then depart into the `InTransit` state. When it arrives, it changes to `Delivered`. If a problem occurs during loading or transit, the vehicle changes to `Delayed` and must resume before continuing.

This allows the vehicle's behavior to change according to its current state without using large conditional statements in the `Vehicle` class.

## Decorator

The `TransportDecorator` delegates the `TransportUnit` operations defined in its interface to the wrapped object, which can be any transport unit, so that the wrapper retains its full functionality while being decorated.

The deleted copy constructor and assignment operator prevent copies of the decorator, because it owns the wrapped object — copying could cause multiple decorators to delete the same wrapper.

There are 3 decorators that our system uses, namely:

- **`InspectionDecorator`** — each `TransportUnit` is examined and inspected, then marked off based on its condition: **good**, **fair**, or **poor**.
- **`InsuranceCoverageDecorator`** — states whether a unit is insured or not.
- **`CustomsClearanceDecorator`** — currently displays a supplied status from the client.

## Building the Project

```bash
make          # builds the taskforge executable
./taskforge   # runs it
make clean    # removes build artifacts
```

## Running with Docker

```bash
# Build the image
docker build -t taskforge-img .

# Remove any existing container with the same name
docker rm taskforgeApp

# Run the container
docker run --name taskforgeApp taskforge-img
```

## Team

| Student Name | Student Number |
| -------- | -------- |
| Thembelisha Skosana | u25224663|
| Rei Piater-Boswell | u25678592 |
| Livia Webber | u24607852 |

