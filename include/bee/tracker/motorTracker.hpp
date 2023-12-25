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

        float getSpeed() override;
    private:
        void tareInternal() override;

        const std::shared_ptr<pros::MotorGroup> m_motors;
        float m_wheelCirc;
        float m_rpm;
        uint8_t m_idx;
};
} // namespace bee