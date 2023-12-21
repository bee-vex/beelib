#include "bee/settler/bound.hpp"

#include <cmath>

#include "pros/rtos.hpp"

namespace bee {
Bound::Bound(std::shared_ptr<Controller> controller, float errorRange, float errorTime)
    : m_controller(controller),
      m_errorRange(errorRange),
      m_errorTime(errorTime) {}

bool Bound::isSettled() {
    float error = m_controller->getError();

    if (std::abs(error) < m_errorRange) {
        if (m_timer == 0) { m_timer = pros::millis(); }

        if (m_timer > m_errorTime) return true;
    } else {
        m_timer = 0;
    }

    return false;
}

void Bound::reset() { m_timer = 0; }
} // namespace bee