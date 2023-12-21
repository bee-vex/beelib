#include "bee/settler/andSettler.hpp"

namespace bee {
AndSettler::AndSettler(std::initializer_list<std::shared_ptr<Settler>> settlers)
    : m_settlers(settlers) {}

bool AndSettler::isSettled() {
    for (std::shared_ptr<Settler> settler : m_settlers) {
        if (!settler->isSettled()) { return false; }
    }

    return true;
}

void AndSettler::reset() {
    for (std::shared_ptr<Settler> settler : m_settlers) { settler->reset(); }
}
} // namespace bee