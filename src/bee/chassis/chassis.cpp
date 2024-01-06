#include "bee/chassis/chassis.hpp"
#include <cmath>
#include "main.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

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

void Chassis::drive_curve(float LeftCurveScale, float RightCurveScale) {
    double A1, A3, CurveA3, CurveA1;
    while(1) {
        A1 = controller.get_analog(ANALOG_RIGHT_X);
        A3 = controller.get_analog(ANALOG_LEFT_Y);

        CurveA3 = (powf(2.718, -(LeftCurveScale / 10)) + powf(2.718, (fabs(A3) - 127) / 10) * (1 - powf(2.718, -(LeftCurveScale / 10)))) * A3;
        CurveA1 = (powf(2.718, -(RightCurveScale / 10)) + powf(2.718, (fabs(A1) - 127) / 10) * (1 - powf(2.718, -(RightCurveScale / 10)))) * A1;

        arcade(CurveA1+CurveA3, CurveA1-CurveA3);
    }
}
} // namespace bee
