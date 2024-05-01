#ifndef PELLET_HPP
#define PELLET_HPP

#include "SDL.h"
#include <iostream>

class Pellet {
public:
    Pellet(int x, int y, float velX, float velY);
    void update(int x, int y, int windowWidth, int windowHieght);
    void render(SDL_Renderer* renderer, int x, int y);
    void deleteTexure(SDL_Texture* texture);
    SDL_Texture* getTexture() const;
    bool isOutOfBoundaries = false;

private:
    float posX;
    float posY;
    float velocityX;
    float velocityY;
    float radius = 20;

    SDL_Texture* texture = nullptr;
};

#endif // PELLET_HPP
