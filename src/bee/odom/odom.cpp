#include "bee/odom/odom.hpp"

#include "bee/math/pose.hpp"

namespace bee {
Pose Odom::getPose() const { return m_pose; }

void Odom::setPose(const Pose& pose) { m_pose = pose; }
} // namespace bee