#include "bee/tracker/tracker.hpp"

namespace bee {
Tracker::Tracker(float offset)
    : m_offset(offset) {}

void Tracker::tare() {
    _tare();
    m_lastPositionResetted = false;
}

float Tracker::getOffset() const { return m_offset; }

float Tracker::getDeltaPosition() {
    if (!m_lastPositionResetted) {
        m_lastPosition = getPosition();
        m_lastPositionResetted = true;
        return 0;
    }

    const float position = getPosition();
    const float change = position - m_lastPosition;
    m_lastPosition = position;
    return change;
}
} // namespace bee