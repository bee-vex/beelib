#pragma once

#include "bee/odom/odom.hpp"
#include "bee/tracker/tracker.hpp"
#include "bee/tracker/headingTracker.hpp"

#include <memory>

namespace bee {
class TwoEncoderOdom : public Odom {
    public:
        TwoEncoderOdom(std::shared_ptr<Tracker> leftTracker, std::shared_ptr<Tracker> horzTracker,
                       std::shared_ptr<HeadingTracker> headingTracker);

        void calibrate() override;

        void update() override;
    private:
        const std::shared_ptr<Tracker> m_leftTracker;
        const std::shared_ptr<Tracker> m_horzTracker;
        const std::shared_ptr<HeadingTracker> m_headingTracker;
};
} // namespace bee