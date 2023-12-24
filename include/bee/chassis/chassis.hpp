#pragma once

#include "pros/motors.hpp"

#include <memory>

namespace bee {
class Chassis {
    public:
        Chassis(std::shared_ptr<pros::MotorGroup> leftMotors, std::shared_ptr<pros::MotorGroup> rightMotors);

        void tank(float leftVoltage, float rightVoltage);

        void arcade(float throttle, float turn);
    private:
        std::shared_ptr<pros::MotorGroup> m_leftMotors;
        std::shared_ptr<pros::MotorGroup> m_rightMotors;
};
} // namespace bee