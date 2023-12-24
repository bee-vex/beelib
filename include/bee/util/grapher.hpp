#pragma once

#include <string>
#include <map>
#include <vector>

namespace bee {
class Grapher {
    public:
        Grapher(const std::string& title, float refreshRate = 10);

        void addDataType(const std::string& name, uint32_t color);

        void update(const std::string& name, float value);

        void start();
    private:
        void loop();

        std::string m_title;
        float m_refreshRate;
        std::map<std::string, uint32_t> m_colors;
        std::map<std::string, std::vector<double>> m_data;
};
} // namespace bee