#include "bee/chassis/chassisController.hpp"

#include "bee/math/util.hpp"

#include "pros/rtos.hpp"

#include <cmath>

namespace bee {
static float capSpeed(float speed, float maxSpeed) {
    if (speed > maxSpeed) { speed = maxSpeed; }
    if (speed < -maxSpeed) { speed = -maxSpeed; }

    return speed;
}

ChassisMotionAlgs::ChassisMotionAlgs(std::shared_ptr<Chassis> chassis, std::shared_ptr<Odom> odom,
                                     std::shared_ptr<Controller> lateralController,
                                     std::shared_ptr<Settler> lateralSettler,
                                     std::shared_ptr<Controller> angularController,
                                     std::shared_ptr<Settler> angularSettler)
    : m_chassis(chassis),
      m_odom(odom),
      m_lateralController(lateralController),
      m_lateralSettler(lateralSettler),
      m_angularController(angularController),
      m_angularSettler(angularSettler) {}

void ChassisMotionAlgs::turnToHeading(float targetHeading, float maxSpeed) {
    m_angularController->reset();
    m_angularSettler->reset();

    while (!m_angularSettler->isSettled()) {
        float error = rollAngle180(targetHeading - m_odom->getPose().theta);

        float output = capSpeed(m_angularController->update(error), maxSpeed);

        m_chassis->arcade(0, output);

        pros::delay(10);
    }

    m_chassis->arcade(0, 0);
}

void ChassisMotionAlgs::turnToPoint(float x, float y, float maxSpeed) {
    m_angularController->reset();
    m_angularSettler->reset();

    Pose target(x, y);

    while (!m_angularSettler->isSettled()) {
        Pose pose = m_odom->getPose();

        float targetHeading = pose.angleTo(target);

        float error = rollAngle180(targetHeading - pose.theta);

        float output = capSpeed(m_angularController->update(error), maxSpeed);

        m_chassis->arcade(0, output);

        pros::delay(10);
    }

    m_chassis->arcade(0, 0);
}

void ChassisMotionAlgs::moveToPoint(float x, float y, const ChassisMotionAlgs::MoveParams& params) {
    m_lateralController->reset();
    m_lateralSettler->reset();
    m_angularController->reset();

    Pose target(x, y);

    bool close = false;

    while (!close || !m_lateralSettler->isSettled()) {
        Pose pose = m_odom->getPose();

        float distance = pose.distance(target);

        if (distance < 7.5 && !close) { close = true; }

        float targetHeading = pose.angleTo(target);
        float angularError = rollAngle180(pose.theta - targetHeading + (params.reversed ? pi : 0));
        float lateralError = distance * std::cos(rollAngle180(pose.theta - targetHeading));

        float lateralOutput = capSpeed(m_lateralController->update(lateralError), params.maxSpeed);
        float angularOutput = m_angularController->update(angularError);

        m_chassis->arcade(lateralOutput, angularOutput);

        pros::delay(10);
    }

    m_chassis->arcade(0, 0);
}

} // namespace bee