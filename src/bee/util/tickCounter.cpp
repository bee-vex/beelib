#include "tickCounter.hpp"

#include "pros/rtos.hpp"

namespace bee {
void TickCounter::resetTicker() { m_time = pros::millis(); }

float TickCounter::getElapsedTime() {
    return static_cast<float>(pros::millis() - m_time) / 1000;
}
} // namespace bee