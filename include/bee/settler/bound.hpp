#pragma once

#include "bee/settler/settler.hpp"
#include "bee/control/closedLoopController.hpp"
#include "bee/util/timer.hpp"

#include <cstdint>
#include <memory>
#include <cmath>

namespace bee {
template <class Output> class Bound : public Settler {
    public:
        Bound(std::shared_ptr<Controller<double, Output>> controller, float errorRange, float errorTime)
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
        std::shared_ptr<Controller<double, Output>> m_controller;

        float m_errorRange;
        float m_errorTime;

        Timer m_timer;
};
} // namespace bee