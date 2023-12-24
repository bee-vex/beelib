#pragma once

namespace bee {
class HeadingTracker {
    public:
        virtual void calibrate() = 0;

        virtual void setRotation(float rotation) = 0;

        virtual float getRotation() = 0;

        float getDeltaRotation();
    private:
        float m_lastRotation = 0;
};
} // namespace bee