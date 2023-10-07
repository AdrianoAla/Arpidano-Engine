//
// Created by Adriano Alasia on 2023-10-05.
//

#ifndef PROJECT_NAME_COLLIDERCOMPONENT_H
#define PROJECT_NAME_COLLIDERCOMPONENT_H

#include "string"
#include "../ECS/ECS.h"
#include "../ECS/Components.h"

class ColliderComponent : public Component {
public:
    int width, height;
    std::string tag;

    ColliderComponent(std::string t) {
        tag = t;

    }

    void init() override {

        if (!(entity)->hasComponent<TransformComponent>()) {
            entity->addComponent<TransformComponent>();
        }

        TransformComponent *transform = &entity->getComponent<TransformComponent>();

        width = transform->width;
        height = transform->height;
    }

    void update() override {

        TransformComponent *transform = &entity->getComponent<TransformComponent>();

        if (transform->position.y < 0) {
            transform->setPos(transform->position.x, 0);
            transform->velocity.y *= -1;
        }

        if (transform->position.y + (float) height > 800) {
            transform->setPos(transform->position.x, (float)(800-height));
        }
    }
};

#endif //PROJECT_NAME_COLLIDERCOMPONENT_H
