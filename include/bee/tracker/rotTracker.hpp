#pragma once

#include "bee/tracker/tracker.hpp"

#include "pros/rotation.hpp"

#include <memory>

namespace bee {
class RotTracker : public Tracker {
    public:
        RotTracker(float offset, std::shared_ptr<pros::Rotation> rotation, float wheelDiameter, float gearing = 1.0);

        float getPosition() override;
    private:
        void _tare() override;

        const std::shared_ptr<pros::Rotation> m_rotation;
        const float m_wheelCirc;
        const float m_gearing;
};
} // namespace bee