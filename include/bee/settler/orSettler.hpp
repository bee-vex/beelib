#pragma once

#include "bee/settler/settler.hpp"

#include <vector>
#include <memory>

namespace bee {
class OrSettler : public Settler {
    public:
        OrSettler(std::initializer_list<std::shared_ptr<Settler>> settlers);

        bool isSettled() override;

        void reset() override;
    private:
        std::vector<std::shared_ptr<Settler>> m_settlers;
};
} // namespace bee