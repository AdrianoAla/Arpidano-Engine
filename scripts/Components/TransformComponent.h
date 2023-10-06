//
// Created by Adriano Alasia on 2023-10-05.
//

#ifndef PROJECT_NAME_TRANSFORMCOMPONENT_H
#define PROJECT_NAME_TRANSFORMCOMPONENT_H

#include "../ECS/ECS.h"
#include "../ECS/Components.h"
#include "../Camera/Camera.h"

class TransformComponent : public Component {
public:
    Vector2 position;
    Vector2 velocity;
    int width, height;

public:

    int x_i() const { return (int) position.x; }
    int y_i() const { return (int) position.y; }

    TransformComponent(float x, float y) {
        position.x = x;
        position.y = y;
        velocity.x = 0;
        velocity.y = 0;
        width = 0;
        height = 0;
    }

    TransformComponent(float x, float y, int w, int h) {
        position.x = x;
        position.y = y;
        velocity.x = 0;
        velocity.y = 0;
        width = w;
        height = h;
    }

    TransformComponent() {
        position.x = 0;
        position.y = 0;
        velocity.x = 0;
        velocity.y = 0;
        width = 0;
        height = 0;
    }

    void setPos(float x, float y) {
        this->position.x = x;
        this->position.y = y;
    }


    void move (float x, float y) {
        position = position.add(Vector2(x,y).mul_v(Game::deltaTime));
    }
};

#endif //PROJECT_NAME_TRANSFORMCOMPONENT_H
