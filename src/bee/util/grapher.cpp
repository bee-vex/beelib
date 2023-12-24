#include "bee/util/grapher.hpp"

#include "pros/screen.hpp"
#include "pros/rtos.hpp"

namespace bee {
constexpr float MAX_CACHE_SIZE = 360;
constexpr float GRAPH_TOP = 14;
constexpr float GRAPH_BOTTOM = 215;
constexpr float GRAPH_LEFT = 25;

Grapher::Grapher(const std::string& title, float refreshRate)
    : m_title(title),
      m_refreshRate(refreshRate) {}

void Grapher::addDataType(const std::string& name, uint32_t color) {
    m_colors.insert({name, color});
    m_data.insert({name, {0.0}});
}

void Grapher::update(const std::string& name, float value) {
    m_data[name].push_back(value);
    if (m_data[name].size() == MAX_CACHE_SIZE + 1) { m_data[name].erase(m_data[name].begin(), m_data[name].end() - 1); }
}

void Grapher::start() {
    pros::Task task([this]() { loop(); });
}

void Grapher::loop() {
    while (true) {
        pros::screen::erase();

        pros::screen::set_pen(COLOR_WHITE);
        pros::screen::print(pros::text_format_e_t::E_TEXT_MEDIUM_CENTER, 1, m_title.c_str());
        pros::screen::draw_line(GRAPH_LEFT, GRAPH_TOP, GRAPH_LEFT, GRAPH_BOTTOM);
        pros::screen::draw_line(GRAPH_LEFT, GRAPH_BOTTOM, GRAPH_LEFT + MAX_CACHE_SIZE, GRAPH_BOTTOM);

        int indexLine = 0;
        for (const auto& item : m_data) {
            pros::screen::set_pen(m_colors[item.first]);
            pros::screen::print(pros::text_format_e_t::E_TEXT_SMALL, GRAPH_LEFT + MAX_CACHE_SIZE,
                                (++indexLine) * 14 + 30, item.first.c_str());
            for (int i = 0; i < item.second.size() - 1; i++) {
                double val1 = item.second[i] * (GRAPH_BOTTOM - GRAPH_TOP);
                double val2 = item.second[i + 1] * (GRAPH_BOTTOM - GRAPH_TOP);
                pros::screen::draw_line(GRAPH_LEFT + i, GRAPH_BOTTOM - val1, GRAPH_LEFT + i + 1, GRAPH_BOTTOM - val2);
            }
        }

        pros::delay(m_refreshRate);
    }
}
} // namespace bee