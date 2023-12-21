#include "bee/tracker/rotTracker.hpp"

#include <cmath>

namespace bee {
RotTracker::RotTracker(float offset, std::shared_ptr<pros::Rotation> rotation, float wheelDiameter, float gearing)
    : Tracker(offset),
      m_rotation(rotation),
      m_wheelCirc(wheelDiameter * M_PI),
      m_gearing(gearing) {}

void RotTracker::_tare() { m_rotation->reset_position(); }

float RotTracker::getPosition() { return m_rotation->get_position() / 36000.0 * m_wheelCirc * m_gearing; }
} // namespace bee