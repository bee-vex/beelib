#pragma once

#include <cmath>

namespace bee {
constexpr float pi = M_PI;

constexpr float rollAngle180(float angle) { return std::remainder(angle, 2 * pi); }

constexpr float degToRad(float deg) { return deg / 180 * pi; }

constexpr float radToDeg(float rad) { return rad / pi * 180; }
} // namespace bee