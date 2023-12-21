#include "control.hpp"

#include "bee/settler/settler.hpp"

namespace bee {
class PID : public Controller {
    public:
        struct Constants {
                float kp;
                float ki;
                float kd;
                float iMax;
        };

        PID(float kp, float ki, float kd, float iMax);

        void getConstants(const Constants& constants);

        void setConstants(const Constants& constants);
    private:
        float _update(float error) override;

        Constants m_constants;
};
} // namespace bee