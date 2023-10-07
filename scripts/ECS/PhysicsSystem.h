//
// Created by Adriano Alasia on 2023-10-06.
//

#ifndef PROJECT_NAME_PHYSICSSYSTEM_H
#define PROJECT_NAME_PHYSICSSYSTEM_H

#include "ECS.h"
#include "Components.h"

class PhysicsSystem {
public:
    std::vector<Entity *> entities;

    PhysicsSystem() {
        entities = Game::world.getEntitiesByComponent<BallControllerComponent>();
    }

    void update() {
        for (auto &entity : entities) {
            entity->getComponent<TransformComponent>().velocity.y += 0.005 * Game::deltaTime;
        }
    }
};

#endif //PROJECT_NAME_PHYSICSSYSTEM_H
