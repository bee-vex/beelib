#pragma once

#include "bee/control/controller.hpp"

namespace bee {
template <typename Error> class HasError {
    public:
        virtual Error getError() = 0;
};

} // namespace bee