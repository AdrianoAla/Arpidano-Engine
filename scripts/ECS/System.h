//
// Created by Adriano Alasia on 2023-10-06.
//

#ifndef PROJECT_NAME_SYSTEM_H
#define PROJECT_NAME_SYSTEM_H

#include "../Game/Game.h"

class System {
public:

    std::vector<std::unique_ptr<Entity>> entities;

    template <typename T> System() {
        entities = Game::world.getEntitiesByComponent<T>();

    }

    virtual void update() {};

};

#endif //PROJECT_NAME_SYSTEM_H
