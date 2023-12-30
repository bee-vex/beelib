#pragma once

#include "controller.hpp"

namespace bee {
template <typename Input, typename Output> class ClosedLoopController : public Controller<Input, Output> {
    public:
        Input getError() { return this->getInput(); }; // alias for getInput
};
} // namespace bee