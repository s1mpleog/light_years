#include "framework/Application.h"
#include "framework/Core.h"
#include "framework/World.h"

namespace ly {
    Application::Application(unsigned int windowWidth, unsigned int windowHeight, const std::string &windowTitle,
                             sf::Uint32 windowStyle) :
                             m_Window{sf::VideoMode(windowWidth, windowHeight),
                                      windowTitle, windowStyle},
                             m_TargetFrameRate{60.f},
                             m_TickClock{},
                             currentWorld{nullptr}  {
    };

    void Application::Run() {
        m_TickClock.restart();
        int x = 12;
        float accumulatedTime = 0;
        float targetDeltaTime = 1.f / m_TargetFrameRate;
        while (m_Window.isOpen()) {
            sf::Event windowEvent{};
            while (m_Window.pollEvent(windowEvent)) {
                if (windowEvent.type == sf::Event::EventType::Closed) {
                    m_Window.close();
                }
            }
            accumulatedTime += m_TickClock.restart().asSeconds();
            while (accumulatedTime > targetDeltaTime) {
                accumulatedTime -= targetDeltaTime;
                TickInternal(targetDeltaTime);
                RenderInternal();
            }
        }
    };

    void Application::TickInternal(float deltaTime) {
        Tick(deltaTime);

        if (currentWorld) {
            currentWorld->BeginPlayInternal();
            currentWorld->TickInternal(deltaTime);
        }
    };

    void Application::RenderInternal() {
        m_Window.clear();
        Render();
        m_Window.display();
    };

    void Application::Render() {
        if(currentWorld) {
			    currentWorld->Render(m_Window);
		    }
    };

    void Application::Tick(float deltaTime) {
    }

};  // namespace ly
