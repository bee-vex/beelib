#pragma once

#include "bee/settler/settler.hpp"
#include "bee/control/control.hpp"

#include <cstdint>
#include <memory>

namespace bee {
class Bound : public Settler {
    public:
        Bound(std::shared_ptr<Controller> controller, float errorRange, float errorTime);

        bool isSettled() override;

        void reset() override;
    private:
        std::shared_ptr<Controller> m_controller;

        float m_errorRange;
        float m_errorTime;

        uint32_t m_timer = 0;
};
} // namespace bee