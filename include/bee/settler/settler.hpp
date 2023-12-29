#pragma once

namespace bee {
class Settler {
    public:
        virtual bool isSettled() = 0;

        virtual void reset();
};
} // namespace bee