#include "bee/util/timer.hpp"

#include "pros/rtos.hpp"

namespace bee {
void Timer::stop() { m_time = 0; }

void Timer::start() { m_time = pros::millis(); }

bool Timer::isStopped() { return m_time == 0; }

float Timer::getElapsedTime() {
    if (m_time == 0) { return 0; }

    return static_cast<float>(pros::millis() - m_time) / 1000;
}
} // namespace bee