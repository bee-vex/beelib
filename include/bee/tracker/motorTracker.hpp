#pragma once

#include "bee/tracker/tracker.hpp"

#include "pros/motors.hpp"

#include <memory>
#include <cstdint>

namespace bee {
class MotorGroupTracker : public Tracker {
    public:
        MotorGroupTracker(float offset, std::shared_ptr<pros::MotorGroup> motors, float wheelDiameter, float rpm,
                          uint8_t idx = 0);

        float getPosition() override;
    private:
        void _tare() override;

        const std::shared_ptr<pros::MotorGroup> m_motors;
        const float m_wheelCirc;
        const float m_rpm;
        const uint8_t m_idx;
};
} // namespace bee