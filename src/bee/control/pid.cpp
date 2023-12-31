#include "bee/control/pid.hpp"

#include <cmath>

namespace bee {
PID::PID(float kp, float ki, float kd, float iMax)
    : m_kp(kp),
      m_ki(ki),
      m_kd(kd),
      m_iMax(iMax) {}

void PID::setKP(float kp) { m_kp = kp; }

void PID::setKI(float ki) { m_ki = ki; }

void PID::setKD(float kd) { m_kd = kd; }

float PID::update(float error) {
    float dt = m_timer.getElapsedTime();

    m_integral += error * dt;
    if (error > m_iMax || std::signbit(error) != std::signbit(m_lastError)) { m_integral = 0; }

    float deltaError = (error - m_lastError) / dt;
    m_lastError = error;

    m_timer.start();

    m_output = error * m_kp + m_integral * m_ki + deltaError * m_kd;

    return m_output;
}

float PID::getError() { return m_lastError; }

void PID::reset() {
    m_integral = 0;
    m_lastError = 0;
}
} // namespace bee