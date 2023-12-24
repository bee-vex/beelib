#include "bee/tracker/inertial.hpp"

#include "bee/math/util.hpp"

namespace bee {
Inertial::Inertial(std::shared_ptr<pros::IMU> imu)
    : m_imu(imu) {}

void Inertial::calibrate() { m_imu->reset(true); }

void Inertial::setRotation(float rotation) { m_imu->set_rotation(radToDeg(rotation)); }

float Inertial::getRotation() { return degToRad(m_imu->get_rotation()); }
} // namespace bee