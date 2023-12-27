#pragma once

#include "bee/control/control.hpp"
#include "bee/util/tickCounter.hpp"

namespace bee {
class PID : public Controller {
    public:
        PID(float kp, float ki, float kd, float iMax);

        void setKP(float kp);

        void reset() override;
    private:
        float updateInternal(float error) override;

        float m_kp;
        float m_ki;
        float m_kd;
        float m_iMax;

        float m_integral;
        float m_lastError;

        TickCounter m_tickCounter;
};
} // namespace bee