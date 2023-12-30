#pragma once

#include "bee/controller/controller.hpp"

namespace bee {

template <typename Error> class HasError {
    public:
        virtual Error getError() = 0;
};


} // namespace bee