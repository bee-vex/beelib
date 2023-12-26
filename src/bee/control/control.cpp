#include "bee/control/control.hpp"

namespace bee {
float Controller::update(float error) {
    m_error = error;
    return updateInternal(error);
}

float Controller::getError() const { return m_error; }

void Controller::reset() {}
} // namespace bee