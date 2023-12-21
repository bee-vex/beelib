#pragma once

namespace bee {
class Settler {
    public:
        virtual void reset();

        virtual bool isSettled() = 0;
};
} // namespace bee