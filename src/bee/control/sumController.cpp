#include "bee/control/sumController.hpp"

namespace bee {
SumController::SumController(std::initializer_list<std::shared_ptr<Controller>> controllers)
    : m_controllers(controllers) {}

float SumController::updateInternal(float error) {
    float sumOutput = 0;

    for (std::shared_ptr<Controller> controller : m_controllers) {
        sumOutput += controller->update(error);
    }

    return sumOutput;
}
} // namespace bee