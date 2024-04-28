#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"

namespace ly {
    class Application;
    class Actor;
    class World {
       public:
        explicit World(Application* owningApp);

        void BeginPlayInternal();
        void TickInternal(float deltaTime);
		    void Render(sf::RenderWindow& window);

        virtual ~World();

        template <typename ActorType>
        weak<ActorType> SpawnActor();

       private:
        static void BeginPlay();
        static void Tick(float deltaTime);
        Application* m_owningApp;
        bool m_beginPlay;

        List<shared<Actor>> m_actors;
        List<shared<Actor>> m_pendingActors;
    };

    template <typename ActorType>
    inline weak<ActorType> World::SpawnActor() {
        shared<ActorType> newActor{new ActorType{this}};
        m_pendingActors.push_back(newActor);
        return newActor;
    };
}  // namespace ly
