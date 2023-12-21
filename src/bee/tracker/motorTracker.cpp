#include "bee/tracker/motorTracker.hpp"

#include <cmath>
#include <iostream>

namespace bee {
MotorGroupTracker::MotorGroupTracker(float offset, std::shared_ptr<pros::MotorGroup> motors, float wheelDiameter,
                                     float rpm, uint8_t idx)
    : Tracker(offset),
      m_motors(motors),
      m_wheelCirc(wheelDiameter * M_PI),
      m_rpm(rpm),
      m_idx(idx) {}

void MotorGroupTracker::_tare() { m_motors->tare_position(); }

static float get_rpm(pros::motor_gearset_e_t encoder_units) {
    switch (encoder_units) {
        case pros::E_MOTOR_GEAR_600: return 600;
        case pros::E_MOTOR_GEAR_200: return 200;
        case pros::E_MOTOR_GEAR_100: return 100;
        default: return 600;
    }
}

float MotorGroupTracker::getPosition() {
    m_motors->set_encoder_units(pros::E_MOTOR_ENCODER_ROTATIONS);

    return m_motors->get_positions()[0] * m_wheelCirc * m_rpm / get_rpm(m_motors->get_gearing()[0]);
}
} // namespace bee