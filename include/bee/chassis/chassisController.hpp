#pragma once

#include "bee/chassis/chassis.hpp"
#include "bee/odom/odom.hpp"
#include "bee/control/control.hpp"
#include "bee/settler/settler.hpp"
#include "bee/math/pose.hpp"

#include <memory>

namespace bee {
class ChassisMotionAlgs {
    public:
        struct MoveParams {
                bool reversed = false;
                float maxSpeed = 127;
        };

        ChassisMotionAlgs(std::shared_ptr<Chassis> chassis, std::shared_ptr<Odom> odom,
                          std::shared_ptr<Controller> lateralController, std::shared_ptr<Settler> lateralSettler,
                          std::shared_ptr<Controller> angularController, std::shared_ptr<Settler> angularSettler);

        void turnToHeading(float targetHeading, float maxSpeed = 127);

        void turnToPoint(float x, float y, float maxSpeed = 127);

        void moveToPoint(float x, float y, const MoveParams& params);
    private:
        std::shared_ptr<Chassis> m_chassis;

        std::shared_ptr<Odom> m_odom;

        std::shared_ptr<Controller> m_lateralController;
        std::shared_ptr<Settler> m_lateralSettler;

        std::shared_ptr<Controller> m_angularController;
        std::shared_ptr<Settler> m_angularSettler;
};
} // namespace bee