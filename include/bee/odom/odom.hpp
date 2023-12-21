#pragma once

#include "bee/math/pose.hpp"

namespace bee {
class Odom {
    public:
        Odom() = default;

        virtual void calibrate() = 0;

        virtual void update() = 0;

        Pose getPose() const;

        void setPose(const Pose& pose);
    protected:
        Pose m_pose = Pose(0, 0);
};
} // namespace bee