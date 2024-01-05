#pragma once

#include <functional>
#include "bee/control/controller.hpp"

namespace bee {

template <typename Input, typename Output, typename... Controllers> class CombinedControllers
    : public Controller<Input, Output> {
        std::tuple<Controllers...> m_controllers;
        std::function<Output(Input, std::tuple<Controllers...>)> m_combine;
    public:
        static_assert(
            (traits::is_controller<Controllers>::value && ...),
            "Controller types passed to CombinedControllers must implement the Controller<Input, Output> interface");

        CombinedControllers(std::tuple<Controllers...> controllers,
                            std::function<Output(Input, std::tuple<Controllers...>)> combine)
            : m_controllers(controllers),
              m_combine(combine) {}

        Output update(Input input) override { return m_combine(input, m_controllers); }

        void reset() override {
            std::apply([](auto&... tuple) { (tuple.reset(), ...); }, m_controllers);
        }
};

} // namespace bee