#include "DeliveredState.h"

DeliveredState* DeliveredState::instance() {
    static DeliveredState singleton;
    return &singleton;
}

std::string DeliveredState::describe() const {
    return "delivered - end of lifecycle";
}