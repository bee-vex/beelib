#pragma once

#include "bee/settler/settler.hpp"

#include <memory>

namespace bee {
class Controller {
    public:
        float update(float error);

        virtual float getError() = 0;
    protected:
        virtual float _update(float error) = 0;
    private:
        float m_error;
};
} // namespace bee