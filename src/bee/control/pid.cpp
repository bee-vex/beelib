#include "bee/control/pid.hpp"

namespace bee {
PID::PID(float kp, float ki, float kd, float iMax)
    : m_kp(kp),
      m_ki(ki),
      m_kd(kd),
      m_iMax(iMax) {}

void PID::setKP(float kp) { m_kp = kp; }

void PID::setKI(float ki) { m_ki = ki; }

void PID::setKD(float kd) { m_kd = kd; }

float PID::updateInternal(float error) {
    const float dt = m_tickCounter.getElapsedTime();

    m_integral += error * dt;

    const float deltaError = (error - m_lastError) / dt;
    m_lastError = error;

    m_tickCounter.resetTicker();

    return error * m_kp + m_integral * m_ki + deltaError * m_kd;
}
} // namespace bee