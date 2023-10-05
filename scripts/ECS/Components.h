//
// Created by Adriano Alasia on 2023-10-05.
//

#ifndef PROJECT_NAME_COMPONENTS_H
#define PROJECT_NAME_COMPONENTS_H

#include "ECS.h"

#include "../Game/Game.h"

class PositionComponent : public Component {
public:
    float xpos, ypos;
public:

    float x() const { return xpos; }
    float y() const { return ypos; }

    int x_i() const { return (int) xpos; }
    int y_i() const { return (int) ypos; }

    void init() override {
        xpos = 0;
        ypos = 0;
    }

    void setPos(float x, float y) {
        this->xpos = x;
        this->ypos = y;
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
    float velocity = 0;

    void init() override {};

    void setVelocity(float v) {
        velocity = v;
    }

    void update() override {
        PositionComponent *position = &entity->getComponent<PositionComponent>();
        velocity += 0.1;
        position->setPos(position->x(), position->y() + velocity);
    }
};

class PlayerComponent : public Component {
public:
    void init() override {};

    void jump() {
        PhysicsComponent *physics = &entity->getComponent<PhysicsComponent>();
        physics->setVelocity(-5);
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
        if (Game::event.type == SDL_KEYDOWN) {
            switch (Game::event.key.keysym.sym) {
                case SDLK_SPACE:
                    entity->getComponent<PlayerComponent>().jump();
                    break;
                default:
                    break;
            }
        }
    }
};

class BirdComponent: public RectangleComponent, public PhysicsComponent, public PlayerComponent, public KeyboardController, public PositionComponent {};

#endif //PROJECT_NAME_COMPONENTS_H