#include "bee/settler/orSettler.hpp"

namespace bee {
OrSettler::OrSettler(std::initializer_list<std::shared_ptr<Settler>> settlers)
    : m_settlers(settlers) {}

bool OrSettler::isSettled() {
    for (std::shared_ptr<Settler> settler : m_settlers) {
        if (settler->isSettled()) { return true; }
    }

    return false;
}

void OrSettler::reset() {
    for (std::shared_ptr<Settler> settler : m_settlers) { settler->reset(); }
}
} // namespace bee