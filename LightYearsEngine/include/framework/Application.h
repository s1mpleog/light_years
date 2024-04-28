#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"

namespace ly {
    class World;
    class Application {
       public:
        Application();
        void Run();

        template <typename WorldType>
        weak<WorldType> LoadWorld();

       private:
        void TickInternal(float deltaTime);
        virtual void Tick(float deltaTime);
        void RenderInternal();
        virtual void Render();
        sf::RenderWindow m_Window;
        float m_TargetFrameRate;
        sf::Clock m_TickClock;

        shared<World> currentWorld;
    };

    template <typename WorldType>
    weak<WorldType> Application::LoadWorld() {
        shared<WorldType> newWorld{new WorldType{this}};
        currentWorld = newWorld;
        return newWorld;
    };
}  // namespace ly
