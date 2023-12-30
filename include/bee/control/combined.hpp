#pragma once

#include <functional>
#include "bee/control/controller.hpp"

namespace bee {

template <typename Input, typename Output, typename... Controllers> class CombinedControllers
    : public Controller<Input, Output> {
        std::tuple<Controllers...> controllers;
        std::function<Output(Input, std::tuple<Controllers...>)> combine;
    public:
        static_assert(
            (is_controller<Controllers>::value && ...),
            "Controller types passed to CombinedControllers must implement the Controller<Input, Output> interface");

        CombinedControllers(std::tuple<Controllers...> controllers,
                            std::function<Output(Input, std::tuple<Controllers...>)> combine)
            : controllers(controllers),
              combine(combine) {}

        Output update(Input input) override { return combine(input, controllers); }

        void reset() override {
            std::apply([](auto&... tuple) { (tuple.reset(), ...); }, controllers);
        }
};

} // namespace bee