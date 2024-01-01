#include "settler.hpp"
#include <functional>

namespace bee {
class FunctionSettler : Settler {
        std::function<bool()> m_settled;
    public:
        FunctionSettler(std::function<bool()> settled)
            : m_settled(settled) {}

        bool isSettled() override { return m_settled(); }
};
} // namespace bee