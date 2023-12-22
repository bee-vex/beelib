#pragma once

namespace bee {
class Controller {
    public:
        float update(float error);

        float getError() const;
    protected:
        virtual float updateInternal(float error) = 0;
    private:
        float m_error;
};
} // namespace bee