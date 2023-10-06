//
// Created by Adriano Alasia on 2023-10-05.
//
#include "Collision.h"
#include "SDL2/SDL.h"
#include "../ECS/ECS.h"
#include "../ECS/Components.h"

bool Collision::AABB(const Entity * entityA, const Entity * entityB) {
    auto &transformA = entityA->getComponent<TransformComponent>();
    auto &transformB = entityB->getComponent<TransformComponent>();

    SDL_Rect recA = {
            (int)transformA.position.x,
            (int)transformA.position.y,
            transformA.width,
            transformA.height
    };

    SDL_Rect recB = {
            (int)transformB.position.x,
            (int)transformB.position.y,
            transformB.width,
            transformB.height
    };

    return (
            recA.x + recA.w >= recB.x &&
            recB.x + recB.w >= recA.x &&
            recA.y + recA.h >= recB.y &&
            recB.y + recB.h >= recA.y
            );
}