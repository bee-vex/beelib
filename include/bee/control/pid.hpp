#pragma once

#include "bee/control/constraints.hpp"
#include "bee/util/timer.hpp"

namespace bee {
class PID : public Controller<float, float>, public HasError<float> {
    public:
        PID(float kp, float ki, float kd, float iMax);

        float update(float error) override;
        void reset() override;

        float getError() override;

        void setKP(float kp);

        void setKI(float ki);

        void setKD(float kd);
    private:
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