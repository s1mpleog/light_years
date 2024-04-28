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
        for (shared<Actor> actor : m_pendingActors) {
            m_actors.push_back(actor);
            actor->BeginPlayInternal();
        };
        m_pendingActors.clear();

        for (shared<Actor> actor : m_actors) {
            actor->Tick(deltaTime);
        };

        Tick(deltaTime);
    };

    World::~World(){};

    void World::BeginPlay() {
        LOG("Began play");
    };

    void World::Tick(float deltaTime) {
        LOG("Tick at framerate %.2f", 1.f / deltaTime);
    };

}  // namespace ly
