#pragma once

#include <memory>

namespace bee {
template <typename Input, typename Output> class Controller {
    public:
        Output update(Input input) {
            m_input = input;
            m_output = updateInternal(input);
            return m_output;
        }

        Input getInput() { return m_input; };

        Output getOutput() { return m_output; };
    protected:
        virtual Output updateInternal(Input input) = 0;
    private:
        Input m_input;
        Output m_output;
};
} // namespace bee