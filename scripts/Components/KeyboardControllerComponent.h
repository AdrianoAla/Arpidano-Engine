//
// Created by Adriano Alasia on 2023-10-05.
//

#ifndef PROJECT_NAME_KEYBOARDCONTROLLERCOMPONENT_H
#define PROJECT_NAME_KEYBOARDCONTROLLERCOMPONENT_H

#include "../ECS/ECS.h"
#include "../ECS/Components.h"

class KeyboardControllerComponent: public Component {
public:
    void init() override {};

    float speed = 0.6;


    void update() override {

        const Uint8* currentKeyStates = SDL_GetKeyboardState( nullptr );

        if (currentKeyStates[SDL_SCANCODE_W]) {
            entity->getComponent<TransformComponent>().move(0, -speed);
        }
        else if (currentKeyStates[SDL_SCANCODE_S]) {
            entity->getComponent<TransformComponent>().move(0, speed);
        }

    }
};

#endif //PROJECT_NAME_KEYBOARDCONTROLLERCOMPONENT_H
