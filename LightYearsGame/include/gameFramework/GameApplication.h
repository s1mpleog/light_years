#pragma once
#include "framework/Application.h"
#include "framework/Core.h"

namespace ly {
    class Actor;
    class GameApplication : public Application {
       public:
        GameApplication();
        virtual void Tick(float deltaTime) override;

       private:
        float m_Counter;
        weak<Actor> actorToDestroy;
    };
}  // namespace ly
