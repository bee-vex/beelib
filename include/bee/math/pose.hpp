#pragma once

namespace bee {
class Pose {
    public:
        float x;
        float y;
        float theta;

        Pose(float x, float y, float theta = 0);

        Pose operator+(const Pose& rhs) const;

        Pose operator-(const Pose& rhs) const;

        Pose operator*(float rhs) const;

        Pose operator/(float rhs) const;

        Pose rotateBy(float rhs) const;

        float distance(const Pose& rhs) const;

        float angleTo(const Pose& rhs) const;
};
} // namespace bee