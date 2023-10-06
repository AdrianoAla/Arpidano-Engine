//
// Created by Adriano Alasia on 2023-10-06.
//

#ifndef PROJECT_NAME_AICONTROLLERCOMPONENT_H
#define PROJECT_NAME_AICONTROLLERCOMPONENT_H

#include "../ECS/ECS.h"
#include "../ECS/Components.h"
#include "../Collision/Collision.h"

class AIControllerComponent : public Component {
    public:
        TransformComponent *transform;
        TransformComponent *followTransform;

        AIControllerComponent() = default;

        AIControllerComponent(Entity *followEntity) {
            followTransform = &followEntity->getComponent<TransformComponent>();
        }

        void init() override {
            transform = &entity->getComponent<TransformComponent>();
        }

        void update() override {
            transform->position.y = followTransform->position.y - 75;
            if (transform->position.y < 0) {
                transform->position.y = 0;
            }
            if (transform->position.y + transform->height > 800) {
                transform->position.y = 800 - transform->height;
            }
        }
};

#endif //PROJECT_NAME_AICONTROLLERCOMPONENT_H
