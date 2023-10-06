//
// Created by Adriano Alasia on 2023-10-06.
//

#include "Camera.h"
#include "../ECS/Components.h"

Camera::Camera() {
    position.x = 0;
    position.y = 0;
    target = nullptr;
}

Camera::Camera(Entity *target) {
    position.x = 0;
    position.y = 0;
    this->target = target;
}

Camera::Camera(bool m) {
    movable = m;
}

void Camera::setTarget(Entity *target) {
    this->target = target;
}

void Camera::update() {
    if (!movable) return;

    if (target != nullptr) {
        position.x = -target->getComponent<TransformComponent>().position.x + 500;
        position.y = -target->getComponent<TransformComponent>().position.y + 400;
    } else {

        const Uint8 *currentKeyStates = SDL_GetKeyboardState(nullptr);


        if (currentKeyStates[SDL_SCANCODE_UP]) {
            position.y += speed * Game::deltaTime;
        }
        if (currentKeyStates[SDL_SCANCODE_DOWN]) {
            position.y -= speed * Game::deltaTime;
        }
        if (currentKeyStates[SDL_SCANCODE_LEFT]) {
            position.x += speed * Game::deltaTime;
        }
        if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
            position.x -= speed * Game::deltaTime;
        }
    }
}
