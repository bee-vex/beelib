#pragma once
#include "bee/settler/settler.hpp"
#include <functional>

namespace bee {

template <typename... Settlers> class CombinedSettlers : public Settler {
        std::tuple<Settlers...> m_settlers;
        std::function<bool(std::tuple<Settlers...>)> m_combine;
    public:
        static_assert((traits::is_settler<Settlers>::value && ...),
                      "Settler types passed to CombinedSettlers must implement the Settler interface");

        CombinedSettlers(std::tuple<Settlers...> settlers, std::function<bool(std::tuple<Settlers...>)> combine)
            : m_settlers(settlers),
              m_combine(combine) {}

        bool isSettled() override { return m_combine(m_settlers); }

        void reset() override {
            std::apply([](auto&... tuple) { (tuple.reset(), ...); }, m_settlers);
        }
};
} // namespace bee