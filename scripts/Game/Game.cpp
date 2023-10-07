#include "Game.h"
#include <iostream>

#include "../ECS/Components.h"
#include "../ECS/ECS.h"
#include "../Collision/Collision.h"

//void DrawTriangle(SDL_Renderer* renderer, SDL_Point point1, SDL_Point point2, SDL_Point point3);

Game::Game() = default;
Game::~Game() = default;

SDL_Event Game::event;
SDL_Renderer* Game::renderer = nullptr;
Camera *Game::camera = nullptr;

bool updating = false;

double Game::deltaTime = 0;
Manager Game::world;

Entity& gameArea = Game::world.addEntity();
Entity& player = Game::world.addEntity();
Entity& ai = Game::world.addEntity();
Entity& ball = Game::world.addEntity();

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if (fullscreen) { flags = SDL_WINDOW_FULLSCREEN; }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Initialized ..." << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if (window) {
            std::cout << "Window created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, flags);

        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }

        isRunning = true;

    } else {
        isRunning = false;
    }

    if (isRunning) {

        ball.addComponent<TransformComponent>(475,375,50,50);
        ball.addComponent<ColliderComponent>("ball");
        ball.addComponent<BallControllerComponent>();
        ball.addComponent<RendererComponent>(255,255,255,255);

        player.addComponent<TransformComponent>(1,50,20,200);
        player.addComponent<ColliderComponent>("player");
        player.addComponent<KeyboardControllerComponent>();
        player.addComponent<RendererComponent>(255,255,255,255);

        ai.addComponent<TransformComponent>(979,200,20,200);
        ai.addComponent<ColliderComponent>("ai");
        ai.addComponent<AIControllerComponent>(&ball);
        ai.addComponent<RendererComponent>(255,255,255,255);

        gameArea.addComponent<TransformComponent>(0,0,1000,800);
        gameArea.addComponent<RendererComponent>(50,50,50,255);

        camera = new Camera();

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
                for (Entity *entity : Game::world.getEntitiesByComponent<ColliderComponent>()) {
                    std::cout << "Entity: " << entity << std::endl;
                }
                isRunning = false;
            }


            if (event.key.keysym.sym == SDLK_SPACE) {
                camera->position = Vector2(0,0);
            }

            if (event.key.keysym.sym == SDLK_r) {
                ball.getComponent<TransformComponent>().position = Vector2(475,375);
            }

            if (event.key.keysym.sym == SDLK_p) {
                updating = !updating;
            }

            break;
        default:
            break;
    }
}

void Game::update() {

    if (!updating) {return;}

    Game::world.update();
    camera->update();

}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 255,0,255,255);
    SDL_RenderClear(renderer);

    Game::world.draw();

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
}
