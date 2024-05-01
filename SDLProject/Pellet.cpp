#include "Pellet.hpp"
#include "SDL.h"
#include "SDL_image.h"

Pellet::Pellet(int x, int y, float velX, float velY)
    : posX(x), posY(y), velocityX(velX), velocityY(velY) {
}

void Pellet::update(int x, int y, int windowWidth, int windowHeight) {
    posX = x;
    posY = y;
    if (posX > (windowWidth - 100) || posY > (windowHeight - 100)) {
        isOutOfBoundaries = true;
        std::cout << "Out of boundaries!" << std::endl;
    }
    if (posX < 100 || posY < 100) {
        isOutOfBoundaries = true;
        std::cout << "Out of boundaries!" << std::endl;
    }
    std::cout << posX << std::endl;
    std::cout << posY << std::endl;
}

void Pellet::render(SDL_Renderer* renderer,int x, int y) {
    if (texture == nullptr) {
        SDL_Surface* imageSurface = IMG_Load("ball.png");
        if (imageSurface == NULL) {
            printf("Unable to load image: %s\n", IMG_GetError());
            return;
        }
        texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
        SDL_FreeSurface(imageSurface);
    }

    if (texture == nullptr) {
        printf("Failed to create pellet texture: %s\n", SDL_GetError());
        return;
    }
    SDL_Rect rect{ posX, posY, radius, radius };
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
    SDL_DestroyTexture(texture);
}


void Pellet::deleteTexure(SDL_Texture* texture) {
    SDL_DestroyTexture(texture);
}
SDL_Texture* Pellet::getTexture() const {
    return texture;
}
