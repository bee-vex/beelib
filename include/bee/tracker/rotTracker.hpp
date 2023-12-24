#pragma once

#include "bee/tracker/tracker.hpp"

#include "pros/rotation.hpp"

#include <memory>

namespace bee {
class RotTracker : public Tracker {
    public:
        RotTracker(float offset, std::shared_ptr<pros::Rotation> rotation, float wheelDiameter, float gearing = 1.0);
        
        void tareInternal() override;

        float getPosition() override;
    private:
        std::shared_ptr<pros::Rotation> m_rotation;
        float m_wheelCirc;
        float m_gearing;
};
} // namespace bee