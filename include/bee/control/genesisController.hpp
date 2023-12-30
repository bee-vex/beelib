#pragma once

#include "bee/control/closedLoopController.hpp"
#include "bee/control/pid.hpp"
#include "constraints.hpp"

namespace bee {
float genesisGainFunction(float error, float min, float max, float roundness, float thickness);

class GenesisController : public Controller<float, float>, public HasError<float> {
    public:
        GenesisController(float min, float max, float roundness, float thickness, float ki, float kd, float iMax);
        
        float update(float error) override;
        void reset() override;
        float getError() override;

    private:
        float m_min;
        float m_max;
        float m_roundness;
        float m_thickness;

        PID m_internalPID;
};
} // namespace bee