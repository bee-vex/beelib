#pragma once

namespace bee {
class TickCounter {
    public:
        TickCounter();

        void startTicker();
        
        void tickerStarted();

        void resetTicker();

        float getTime();
};
} // namespace bee