#pragma once

#include "bee/control/control.hpp"

#include <vector>
#include <memory>

namespace bee {
class SumController : public Controller {
    public:
        SumController(std::initializer_list<std::shared_ptr<Controller>> controllers);
    private:
        float updateInternal(float error) override;

        std::vector<std::shared_ptr<Controller>> m_controllers;
};
} // namespace bee