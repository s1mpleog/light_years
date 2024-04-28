#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"

ly::Application* GetApplication() {
    return new ly::GameApplication{};
};
namespace ly {
    GameApplication::GameApplication() {
        weak<World> newWorld = LoadWorld<World>();
        newWorld.lock()->SpawnActor<Actor>();
        actorToDestroy = newWorld.lock()->SpawnActor<Actor>();
        m_Counter = 0;
    };
    void GameApplication::Tick(float deltaTime) {
        m_Counter += deltaTime;
        if (m_Counter > 2.f) {
            if (!actorToDestroy.expired()) {
                actorToDestroy.lock()->Destroy();
            }
        }
    }
}  // namespace ly
