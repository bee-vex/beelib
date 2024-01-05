#pragma once
#include <type_traits>

namespace bee {
class Settler {
    public:
        virtual bool isSettled() = 0;

        virtual void reset();
};

namespace traits {

template <typename T> using is_settler = std::is_base_of<Settler, T>;

} // namespace traits
} // namespace bee