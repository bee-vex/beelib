#include "bee/control/control.hpp"

namespace bee {
float Controller::update(float error) {
    m_error = error;
    return _update(error);
}

float Controller::getError() { return m_error; }
} // namespace bee