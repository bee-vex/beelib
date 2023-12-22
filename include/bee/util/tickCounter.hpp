#pragma once

#include <cstdint>

namespace bee {
class TickCounter {
    public:
        TickCounter() = default;
        
        void resetTicker();

        float getElapsedTime();
    private:
        uint32_t m_time = 0;
};
} // namespace bee