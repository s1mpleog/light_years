#include "framework/World.h"
#include "framework/Core.h"
#include "framework/Actor.h"

namespace ly {
    World::World(Application* owningApp)
        : m_owningApp{owningApp},
          m_beginPlay{false},
          m_actors{},
          m_pendingActors{} {};

    void World::BeginPlayInternal() {
        if (!m_beginPlay) {
            m_beginPlay = true;
            BeginPlay();
        }
    }

    void World::TickInternal(float deltaTime) {
        for (const shared<Actor>& actor : m_pendingActors) {
            m_actors.push_back(actor);
            actor->BeginPlayInternal();
        };
        m_pendingActors.clear();

        for (auto iter = m_actors.begin(); iter != m_actors.end();) {
            if (iter->get()->IsPendingDestroy()) {
                iter = m_actors.erase(iter);
            } else {
                iter->get()->TickInternal(deltaTime);
                ++iter;
            }
        }

        Tick(deltaTime);
    };

    World::~World()= default;

    void World::BeginPlay() {
        LOG("Began play");
    };

    void World::Tick(float deltaTime) {
        LOG("Tick at framerate %.2f", 1.f / deltaTime);
    };

	  void World::Render(sf::RenderWindow &window) {
				for(auto& actor : m_actors) {
			    actor->Render(window);
		    }
	  };

}  // namespace ly
