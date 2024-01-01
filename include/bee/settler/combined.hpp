#pragma once
#include "bee/settler/settler.hpp"
#include <functional>

namespace bee {
    
template <typename... Settlers> class CombinedSettlers
    : public Settler {
        std::tuple<Settlers...> settlers;
        std::function<bool(std::tuple<Settlers...>)> combine;
    public:
        static_assert(
            (traits::is_settler<Settlers>::value && ...),
            "Settler types passed to CombinedSettlers must implement the Settler interface");

        CombinedSettlers(std::tuple<Settlers...> settlers,
                            std::function<bool(std::tuple<Settlers...>)> combine)
            : settlers(settlers),
              combine(combine) {}

        bool isSettled() override {
            return combine(settlers);
        }

        void reset() override {
            std::apply([](auto&... tuple) { (tuple.reset(), ...); }, settlers);
        }
};
}