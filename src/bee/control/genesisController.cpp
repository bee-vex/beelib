#include "bee/control/genesisController.hpp"

#include <cmath>

namespace bee {
float genesisGainFunction(float error, float min, float max, float roundness, float thickness) {
    return (min - max) * std::pow(std::abs(error), roundness) /
               (std::pow(std::abs(error), roundness) + std::pow(thickness, roundness)) +
           max;
}

GenesisController::GenesisController(float min, float max, float roundness, float thickness, float ki, float kd,
                                     float iMax)
    : m_min(min),
      m_max(max),
      m_roundness(roundness),
      m_thickness(thickness),
      m_internalPID(0, ki, kd, iMax) {}

float GenesisController::update(float error) {
    m_internalPID.setKP(genesisGainFunction(error, m_min, m_max, m_roundness, m_thickness));

    return m_internalPID.update(error);
}

void GenesisController::reset() { m_internalPID.reset(); }

float GenesisController::getError() { return m_internalPID.getError(); }
} // namespace bee