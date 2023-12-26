#include "bee/tracker/rotTracker.hpp"

#include "bee/math/util.hpp"

namespace bee {
RotTracker::RotTracker(float offset, std::shared_ptr<pros::Rotation> rotation, float wheelDiameter, float gearing)
    : Tracker(offset),
      m_rotation(rotation),
      m_wheelCirc(wheelDiameter * pi),
      m_gearing(gearing) {}

void RotTracker::tareInternal() { m_rotation->reset_position(); }

float RotTracker::getPosition() { return m_rotation->get_position() / 36000.0 * m_wheelCirc / m_gearing; }

float RotTracker::getSpeed() { return m_rotation->get_velocity() / 36000.0 * m_wheelCirc / m_gearing; }
} // namespace bee