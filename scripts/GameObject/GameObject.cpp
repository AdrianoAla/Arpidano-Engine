//
// Created by Adriano Alasia on 2023-10-05.
//
#include "GameObject.h"

GameObject::GameObject(SDL_Renderer* renderer) {
    this->renderer = renderer;
    this->x = 0;
    this->y = 0;
}

GameObject::~GameObject() {}

void GameObject::update() {
    x++;
    y++;
    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = x;
    srcRect.y = y;
}

void GameObject::render() {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &srcRect);
}