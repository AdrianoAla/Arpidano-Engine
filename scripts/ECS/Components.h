//
// Created by Adriano Alasia on 2023-10-05.
//

#ifndef PROJECT_NAME_COMPONENTS_H
#define PROJECT_NAME_COMPONENTS_H

#include "ECS.h"

#include "../Game/Game.h"
#include "../Utils/Vector2.h"

class PositionComponent : public Component {
private:
    Vector2 position;
public:

    float x() const { return position.x; }
    float y() const { return position.y; }

    int x_i() const { return (int) position.x; }
    int y_i() const { return (int) position.y; }

    PositionComponent(float x, float y) {
        position.x = x;
        position.y = y;
    }

    PositionComponent() {
        position.x = 0;
        position.y = 0;
    }

    void setPos(float x, float y) {
        this->position.x = x;
        this->position.y = y;
    }
};

class RectangleComponent : public Component {
public:
    int width, height;

    SDL_Color color = { 0, 0, 0, 255 };

    RectangleComponent(int w, int h) {
        width = w;
        height = h;
    }

    void setColor(SDL_Color c) {
        color = c;
    }

    int w() const { return width; }
    int h() const { return height; }

    void init() override {};

    void setRect(int w, int h) {
        this->width = w;
        this->height = h;
    }

    void draw() override {
        PositionComponent *position = &entity->getComponent<PositionComponent>();
        SDL_Rect rect = { position->x_i(), position->y_i(), width, height };
        SDL_SetRenderDrawColor(Game::renderer, color.r, color.g, color.b, color.a);
        SDL_RenderFillRect(Game::renderer, &rect);
    }

};

class PhysicsComponent : public Component {
public:
    Vector2 velocity;

    void init() override {};

    void setVelocity(float x, float y) {
        velocity.x = x;
        velocity.y = y;
    }

    void update() override {
        PositionComponent *position = &entity->getComponent<PositionComponent>();

        velocity.y /= 1.01;
        velocity.x /= 1.01;

        position->setPos(position->x() + velocity.x, position->y() + velocity.y);
    }
};

class PlayerComponent : public Component {
public:
    void init() override {};

    void jump(float x, float y) {
        PhysicsComponent *physics = &entity->getComponent<PhysicsComponent>();
        physics->setVelocity(x, y);
    }

    void accelerate(float x, float y) {
        PhysicsComponent *physics = &entity->getComponent<PhysicsComponent>();
        physics->velocity.x += x;
        physics->velocity.y += y;
    }

};

class PipeComponent : public Component {
public:
    void init() override {};

    void update() override {
        PositionComponent *position = &entity->getComponent<PositionComponent>();
        position->setPos(position->x() - 1, position->y());
    }
};

class KeyboardController: public Component {
public:
    void init() override {};

    void update() override {

        const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

        if (currentKeyStates[SDL_SCANCODE_W]) {
            entity->getComponent<PlayerComponent>().accelerate(0, -0.3);
        }
        if (currentKeyStates[SDL_SCANCODE_S]) {
            entity->getComponent<PlayerComponent>().accelerate(0, 0.3);
        }
        if (currentKeyStates[SDL_SCANCODE_A]) {
            entity->getComponent<PlayerComponent>().accelerate(-0.3, 0);
        }
        if (currentKeyStates[SDL_SCANCODE_D]) {
            entity->getComponent<PlayerComponent>().accelerate(0.3, 0);
        }
    }
};

#endif //PROJECT_NAME_COMPONENTS_H