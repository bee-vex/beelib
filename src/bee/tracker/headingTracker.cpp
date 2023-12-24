#include "bee/tracker/headingTracker.hpp"

namespace bee {
float HeadingTracker::getDeltaRotation() {
    const float rotation = getRotation();
    const float change = rotation - m_lastRotation;
    m_lastRotation = rotation;
    return change;
}
} // namespace bee