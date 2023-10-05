//
// Created by Adriano Alasia on 2023-10-05.
//

#ifndef STRATEGY_GAME_GAMEOBJECT_H
#define STRATEGY_GAME_GAMEOBJECT_H

#include "SDL.h"
#include "../Game/Game.h"

class GameObject {
public:
    GameObject(SDL_Renderer* renderer);
    ~GameObject();

    void update();
    void render();

private:
    int x;
    int y;

    SDL_Rect srcRect;
    SDL_Renderer* renderer;
};


#endif //STRATEGY_GAME_GAMEOBJECT_H