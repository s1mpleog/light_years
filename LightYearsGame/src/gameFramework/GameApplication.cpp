#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"

ly::Application* GetApplication() {
    return new ly::GameApplication{};
};
namespace ly {
    GameApplication::GameApplication()
        : Application{ 600, 980, "Light Years",
                      sf::Style::Titlebar | sf::Style::Close }
    {
        weak<World> newWorld = LoadWorld<World>();
        newWorld.lock()->SpawnActor<Actor>();
        actorToDestroy = newWorld.lock()->SpawnActor<Actor>();
		    actorToDestroy.lock()->setTexture("/home/simple_og/programming/c++/games/light_years/LightYearsGame/assets"
		                                      "/SpaceShooterRedux/PNG/playerShip1_blue.png");
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

