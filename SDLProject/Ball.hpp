#ifndef Ball_hpp
#define Ball_hpp

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <string>

class Ball {
public:

    Ball();

    void update(int windowWidth, int windowHeight, float deltaTime);

    void render(SDL_Renderer* renderer,int x,int y);
    
    bool isOutOfBoundaries = false;

    void deleteTexture(SDL_Texture* texture);

    SDL_Texture* getTexture() const;
    
    void clean();

private:
    float deltaTime;
    int width = 100;
    int height = 100;
    int cnt = 0;

    int ballX = 200;
    int ballY = 43;
    int velocityX = 2;
    int velocityY = 2;

    float time = 0; 

    int mouseX = 0, mouseY = 0;
    int offsetCorrectionX = 0, offsetCorrectionY = 0;
    SDL_Texture* texture = nullptr;
};

#endif // Ball_hpp
