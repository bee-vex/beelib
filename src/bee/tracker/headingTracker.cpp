#include "bee/tracker/headingTracker.hpp"

namespace bee {
float HeadingTracker::getDeltaRotation() {
    float rotation = getRotation();
    float change = rotation - m_lastRotation;
    m_lastRotation = rotation;
    return change;
}
} // namespace bee