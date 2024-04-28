#include "framework/Actor.h"
#include "framework/Core.h"

namespace ly {
    Actor::Actor(World* owningWorld, const std::string& texturePath)
        : m_owningWord{owningWorld},
          m_beginPlay{false} ,
	        m_Sprite{},
	        m_Texture{}
	      {
	              setTexture(texturePath);
	      };

    Actor::~Actor() {
        LOG("actor destroyed");
    };

    void Actor::BeginPlayInternal() {
        if (!m_beginPlay) {
            m_beginPlay = true;
            BeginPlay();
        }
    }

    void Actor::BeginPlay(){
        LOG("Actor begin Play")};

    void Actor::Tick(float deltaTime) {
        LOG("Actor Ticking")
    }
	  void Actor::setTexture(const std::string &texturePath) {
		  m_Texture.loadFromFile(texturePath);
		  m_Sprite.setTexture(m_Texture);
		  unsigned int textureWidth = m_Texture.getSize().x;
		  unsigned int textureHeight = m_Texture.getSize().y;

		  m_Sprite.setTextureRect(sf::IntRect{sf::Vector2i{},
		                                      sf::Vector2i{static_cast<int>(textureWidth),
		                                                   static_cast<int>(textureHeight)} });
	  }
	  void Actor::Render(sf::RenderWindow &window) {
		  if (IsPendingDestroy())
			    return;
		  window.draw(m_Sprite);
	  }
	  void Actor::TickInternal(float deltaTime) {
		  if(!m_IsPendingDestroy) {
			  Tick(deltaTime);
		  }
	  }
}  // namespace ly
