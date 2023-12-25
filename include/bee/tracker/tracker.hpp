#pragma once

namespace bee {
class Tracker {
    public:
        Tracker(float offset);

        float getOffset() const;

        void tare();

        virtual float getPosition() = 0;

        virtual float getSpeed() = 0;

        float getDeltaPosition();
    private:
        virtual void tareInternal() = 0;

        float m_offset;
        float m_lastPosition = 0;
};
} // namespace bee