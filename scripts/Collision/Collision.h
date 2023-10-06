//
// Created by Adriano Alasia on 2023-10-05.
//

#ifndef PROJECT_NAME_COLLISION_H
#define PROJECT_NAME_COLLISION_H

#include "SDL2/SDL.h"
#include "../ECS/ECS.h"

class Collision {
public:
    static bool AABB(const Entity * entityA, const Entity * entityB);

    void updateCollisions();
};


#endif //PROJECT_NAME_COLLISION_H
