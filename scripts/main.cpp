#include <SDL2/SDL.h>
#include "Game/Game.h"

static const int width = 800;
static const int height = 600;

Game *game = nullptr;

int main() {

    game = new Game();

    game->init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, false);

    const int FPS = 60;
    const int FPS_DELAY = 1000/FPS;

    Uint32 frameStart;
    int frameTime;

    while (game->running()) {

        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (FPS_DELAY > frameTime) {
            SDL_Delay(FPS_DELAY - frameTime);
        }
    }

    game->clean();

}