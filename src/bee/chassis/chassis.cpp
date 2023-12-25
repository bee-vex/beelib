#include "bee/chassis/chassis.hpp"

#include <cmath>

namespace bee {
Chassis::Chassis(std::shared_ptr<pros::MotorGroup> leftMotors, std::shared_ptr<pros::MotorGroup> rightMotors)
    : m_leftMotors(leftMotors),
      m_rightMotors(rightMotors) {}

void Chassis::tank(float leftVoltage, float rightVoltage) {
    m_leftMotors->move(std::round(leftVoltage));
    m_rightMotors->move(std::round(rightVoltage));
}

void Chassis::arcade(float throttle, float turn) {
    float leftVoltage = throttle + turn;
    float rightVoltage = throttle - turn;

    float mag = std::max(std::abs(leftVoltage), std::abs(rightVoltage)) / 127;

    if (mag > 1) {
        leftVoltage /= mag;
        rightVoltage /= mag;
    }

    tank(leftVoltage, rightVoltage);
}
} // namespace bee