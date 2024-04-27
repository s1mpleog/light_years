#pragma once
#include <SFML/Graphics.hpp>

namespace ly {
    class Application {
       public:
        Application();

        void Run();

       private:
        sf::RenderWindow m_Window;
    };
}  // namespace ly
