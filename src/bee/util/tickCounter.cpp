#include "tickCounter.hpp"

#include "pros/rtos.hpp"

namespace bee {
void TickCounter::resetTicker() { m_time = 0; }

float TickCounter::getElapsedTime() {
    if (m_time == 0) {
        m_time = pros::millis();
        return 0;
    }

    return static_cast<float>(pros::millis() - m_time) / 1000;
}
} // namespace bee