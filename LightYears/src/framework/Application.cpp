#include "framework/Application.h"

namespace ly {
    Application::Application()
        : m_Window{sf::VideoMode(1024, 1440), "Light Years"} {};
    void Application::Run() {
        while (m_Window.isOpen()) {
            sf::Event windowEvent;
            while (m_Window.pollEvent(windowEvent)) {
                if (windowEvent.type == sf::Event::EventType::Closed) {
                    m_Window.close();
                }
            }
        }
    };
};  // namespace ly
