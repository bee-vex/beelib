#include "bee/tracker/tracker.hpp"

namespace bee {
Tracker::Tracker(float offset)
    : m_offset(offset) {}

float Tracker::getOffset() const { return m_offset; }

void Tracker::tare() {
    tareInternal();
    m_lastPosition = getPosition();
}

float Tracker::getDeltaPosition() {
    float position = getPosition();
    float change = position - m_lastPosition;
    m_lastPosition = position;
    return change;
}
} // namespace bee