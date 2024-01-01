#pragma once

#include <memory>

namespace bee {
template <typename Input, typename Output> class Controller {
    public:
        virtual Output update(Input input) = 0;

        virtual void reset() = 0;
};

namespace traits {
inline std::false_type is_controller_impl(...) { return std::false_type(); };

template <typename Input, typename Output>
inline std::true_type is_controller_impl(Controller<Input, Output> const volatile&) {
    return std::true_type();
};

template <typename T> using is_controller = decltype(is_controller_impl(std::declval<T&>()));

} // namespace traits
} // namespace bee