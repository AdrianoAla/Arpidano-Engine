#include <SDL2/SDL.h>
#include "Game/Game.h"

static const int width = 1000;
static const int height = 800;

Game *game = nullptr;

int main() {

    game = new Game();

    game->init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, false);

    const int FPS = 1;
    const int FPS_DELAY = 1000/FPS;



    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;


    int frameTime;

    while (game->running()) {

        LAST = NOW;

        game->render();
        game->update();
        game->handleEvents();

        NOW = SDL_GetPerformanceCounter();

        game->deltaTime = (double)((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency() / (double)(FPS_DELAY/1000) );

    }

    game->clean();

}