#pragma once

#include <memory>

namespace bee {
template <typename Input, typename Output> class Controller {
    public:
        virtual Output update(Input input) = 0;
        
        virtual void reset() = 0;
};
} // namespace bee