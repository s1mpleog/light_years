#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"
#include "framework/Object.h"

namespace ly {
    class World;
    class Actor : public Object {
       public:
        explicit Actor(World* owningWorld, const std::string& texturePath = "");
        ~Actor() override;
        void BeginPlayInternal();
		    void TickInternal(float deltaTime);
        virtual void BeginPlay();
        virtual void Tick(float deltaTime);
		    void setTexture(const std::string& texturePath);
		    void Render(sf::RenderWindow& window);

       private:
        World* m_owningWord;
        bool m_beginPlay;

		    sf::Sprite m_Sprite;
		    sf::Texture m_Texture;
    };
}  // namespace ly
