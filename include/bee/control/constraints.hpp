#pragma once

#include "bee/controller/controller.hpp"

namespace bee {

template <typename Error> class HasError {
    public:
        virtual Error getError() = 0;
};

class HasTime {
    public:
        virtual uint32_t getRuntime() = 0;
};

} // namespace bee