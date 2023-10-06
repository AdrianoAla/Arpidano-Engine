//
// Created by Adriano Alasia on 2023-10-06.
//

#ifndef PROJECT_NAME_RENDERERCOMPONENT_H
#define PROJECT_NAME_RENDERERCOMPONENT_H

#include "../ECS/Components.h"
#include "../ECS/ECS.h"
#include "SDL2/SDL.h"

class RendererComponent : public Component {

public:

    TransformComponent *transformComponent;
    SDL_Color color = {255,0,0,255};

    RendererComponent() = default;

    RendererComponent(SDL_Color color) {
        this->color = color;
    }

    RendererComponent(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
        color = {r,g,b,a};
    }

    void init() override {
        if (!entity->hasComponent<TransformComponent>()) {
            entity->addComponent<TransformComponent>();
        }

        transformComponent = &entity->getComponent<TransformComponent>();
    }

    void draw() override {

        Vector2 cameraPosition = Game::camera->position;
        Vector2 updated_position = transformComponent->position.add(cameraPosition);

        if (updated_position.x > 1000 || updated_position.x + (float) transformComponent->width < 0 || updated_position.y > 800 || updated_position.y  + (float) transformComponent->height  < 0) {
            return;
        }

        SDL_SetRenderDrawColor(Game::renderer, color.r, color.g, color.b, color.a);

        SDL_Rect destRect = {
                (int) updated_position.x,
                (int) updated_position.y,
                transformComponent->width,
                transformComponent->height
        };

        SDL_RenderFillRect(Game::renderer, &destRect);
    }
};

#endif //PROJECT_NAME_RENDERERCOMPONENT_H
