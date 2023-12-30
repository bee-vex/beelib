#pragma once

#include "bee/control/closedLoopController.hpp"
#include "bee/util/timer.hpp"

namespace bee {
class PID : public ClosedLoopController<float, float> {
    public:
        PID(float kp, float ki, float kd, float iMax);

        void setKP(float kp);

        void setKI(float ki);

        void setKD(float kd);

        void reset() override;
    private:
        float updateInternal(float error) override;

        float m_kp;
        float m_ki;
        float m_kd;
        float m_iMax;

        float m_integral;
        float m_lastError;

        float m_output;

        Timer m_timer;
};
} // namespace bee