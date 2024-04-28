#include "framework/Actor.h"
#include "framework/Core.h"

namespace ly {
    Actor::Actor(World* owningWorld)
        : m_owningWord{owningWorld},
          m_beginPlay{false} {}

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
}  // namespace ly
