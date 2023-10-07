//
// Created by Adriano Alasia on 2023-10-06.
//

#ifndef PROJECT_NAME_BALLCONTROLLERCOMPONENT_H
#define PROJECT_NAME_BALLCONTROLLERCOMPONENT_H

#include "../ECS/Components.h"
#include "../ECS/ECS.h"
#include "../Game/Game.h"
#include "../Collision/Collision.h"

class BallControllerComponent : public Component {
public:

        TransformComponent *transformComponent;
        ColliderComponent *colliderComponent;

        BallControllerComponent() = default;

        void init() override {
            if (!entity->hasComponent<TransformComponent>()) {
                entity->addComponent<TransformComponent>();
            }

            if (!entity->hasComponent<ColliderComponent>()) {
                entity->addComponent<ColliderComponent>("ball");
            }

            transformComponent = &entity->getComponent<TransformComponent>();
            colliderComponent = &entity->getComponent<ColliderComponent>();
            transformComponent->reset();
        }

        void update() override {

            if (transformComponent->position.y + (float) transformComponent->height >= 800) {
                float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
                transformComponent->velocity.y = - (r/3 + 2);

            }


            if (transformComponent->position.x + transformComponent->width/2 < 0) {

                // Player lost
                for (Entity *e : Game::world.getEntitiesByComponent<TransformComponent>()) {
                    e->getComponent<TransformComponent>().resetPosition();
                }
                transformComponent->reset();

            }

            if (transformComponent->position.x + (float) transformComponent->width > 1000) {
                // Player won (literally not possible)
                transformComponent->velocity = transformComponent->velocity.mul(Vector2(-1.0f,1.0));
                transformComponent->position = transformComponent->position.add(transformComponent->velocity.mul_v(Game::deltaTime));
            }


            for (Entity *e : Game::world.getEntitiesByComponent<ColliderComponent>()) {

                if (e == entity) continue;

                if (Collision::AABB(entity, e)) {
                    entity->getComponent<TransformComponent>().velocity = entity->getComponent<TransformComponent>().velocity.mul(Vector2(-1.0f,1.0));
                    while (Collision::AABB(entity, e)) {
                        entity->getComponent<TransformComponent>().position = entity->getComponent<TransformComponent>().position.add(entity->getComponent<TransformComponent>().velocity.mul_v(Game::deltaTime));
                    }
                }
            }
        }
};

#endif //PROJECT_NAME_BALLCONTROLLERCOMPONENT_H
