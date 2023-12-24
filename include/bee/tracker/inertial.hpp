#pragma once

#include "bee/tracker/headingTracker.hpp"

#include "pros/imu.hpp"

#include <memory>

namespace bee {
class Inertial : public HeadingTracker {
    public:
        Inertial(std::shared_ptr<pros::IMU> imu);

        void calibrate() override;

        void setRotation(float rotation) override;

        float getRotation() override;
    private:
        const std::shared_ptr<pros::IMU> m_imu;
};
} // namespace bee