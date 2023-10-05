#include "Game.h"
#include <iostream>

#include "../ECS/Components.h"
#include "../ECS/ECS.h"

//void DrawTriangle(SDL_Renderer* renderer, SDL_Point point1, SDL_Point point2, SDL_Point point3);

Game::Game() = default;
Game::~Game() = default;

SDL_Event Game::event;
SDL_Renderer* Game::renderer = nullptr;

Manager manager;
Entity& player(manager.addEntity());

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if (fullscreen) { flags = SDL_WINDOW_FULLSCREEN; }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Initialized ..." << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if (window) {
            std::cout << "Window created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);

        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }

        player.addComponent<PositionComponent>();
        player.addComponent<RectangleComponent>(50, 50);
        player.addComponent<PhysicsComponent>();
        player.addComponent<PlayerComponent>();
        player.addComponent<KeyboardController>();

        isRunning = true;

    } else {
        isRunning = false;
    }
}

void Game::handleEvents() {

    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;

        case SDL_KEYUP:
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                isRunning = false;
            }
            break;

        default:
            break;
    }
}

void Game::update() {

    manager.update();

    //std::cout << player.getComponent<PositionComponent>().x() << " " << player.getComponent<PositionComponent>().y() << std::endl;

    int x = player.getComponent<PositionComponent>().x_i();
    int y = player.getComponent<PositionComponent>().y_i();
    player.getComponent<RectangleComponent>().setColor({ (Uint8) x, (Uint8) y, 0, 255});
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 255,255,255,0);
    SDL_RenderClear(renderer);

    // This is where we would add stuff to render

    manager.draw();

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
}
