#include "bee/math/pose.hpp"

#include <cmath>

namespace bee {
Pose::Pose(float x, float y, float theta)
    : x(x),
      y(y),
      theta(theta) {}

Pose Pose::operator+(const Pose& rhs) const { return Pose(x + rhs.x, y + rhs.y, theta); }

Pose Pose::operator-(const Pose& rhs) const { return Pose(x - rhs.x, y - rhs.y, theta); }

Pose Pose::operator*(float rhs) const { return Pose(x * rhs, y * rhs, theta); }

Pose Pose::operator/(float rhs) const { return Pose(x / rhs, y / rhs, theta); }

Pose Pose::rotateBy(float rhs) const {
    float s = std::sin(rhs);
    float c = std::cos(rhs);
    return Pose(x * c - y * s, x * s + y * c, theta);
}

float Pose::distance(const Pose& rhs) const { return std::hypot(x - rhs.x, y - rhs.y); }

float Pose::angleTo(const Pose& rhs) const { return M_PI - std::atan2(y - rhs.y, x - rhs.x); }
} // namespace bee