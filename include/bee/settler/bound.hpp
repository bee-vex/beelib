#pragma once

#include "bee/settler/settler.hpp"
#include "bee/control/constraints.hpp"
#include "bee/util/timer.hpp"

#include <cstdint>
#include <memory>
#include <cmath>

namespace bee {
template <class Controller> class Bound : public Settler {
    static_assert(
	    std::is_base_of<HasError<float>, Controller>::value, 
	    "Controller passed to Bound settler does not implement HasError<float>");

    public:
        Bound(std::shared_ptr<Controller> controller, float errorRange, float errorTime)
            : m_controller(controller),
              m_errorRange(errorRange),
              m_errorTime(errorTime) {}

        bool isSettled() override {
            if (std::abs(m_controller->getError()) < m_errorRange) {
                if (m_timer.isStopped()) { m_timer.start(); }

                if (m_timer.getElapsedTime() > m_errorTime) return true;
            } else {
                m_timer.stop();
            }

            return false;
        }

        void reset() override { m_timer.stop(); }
    private:
        std::shared_ptr<Controller> m_controller;

        float m_errorRange;
        float m_errorTime;

        Timer m_timer;
};
} // namespace bee