#pragma once

#include <cstdint>

namespace bee {
class Timer {
    public:
        Timer() = default;
        
        void stop();

        void start();

        bool isStopped();

        float getElapsedTime();
    private:
        uint32_t m_time = 0;
};
} // namespace bee