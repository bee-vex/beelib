#pragma once

#include "bee/control/control.hpp"
#include "bee/control/pid.hpp"

namespace bee {
float genesisGainFunction(float error, float min, float max, float roundness, float thickness);

class GenesisController : public Controller {
    public:
        GenesisController(float min, float max, float roundness, float thickness, float ki, float kd, float iMax);
        
        void reset() override;
    private:
        float updateInternal(float error) override;

        float m_min;
        float m_max;
        float m_roundness;
        float m_thickness;

        PID m_internalPID;
};
} // namespace bee