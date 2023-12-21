#pragma once

namespace bee {
class Tracker {
    public:
        Tracker(float offset);

        float getOffset() const;

        void tare();

        virtual float getPosition() = 0;

        float getDeltaPosition();
    protected:
        virtual void _tare() = 0;
    private:
        void initialize();

        const float m_offset;
        float m_lastPosition = 0;

        bool m_lastPositionResetted = false;
};
} // namespace bee