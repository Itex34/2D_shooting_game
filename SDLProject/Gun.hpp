#ifndef Gun_hpp
#define Gun_hpp

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <string>
class Game;
class Gun {
public:
    ~Gun();

    Gun();
    void update(int windowWidth, int windowHeight);
    void render(SDL_Renderer* renderer, int windowWidth, int windowHeight);
    void shoot(int windowWidth, int windowHeight);
    void cleanup();
private:
    int width = 200;
    int height = 200;
    int cnt = 0;

    int gunX = 550;
    int gunY = 400;
    
    int pelletOffsetCorrectionX = 0;
    int pelletOffsetCorrectionY = 0;
    int pelletX = gunX + pelletOffsetCorrectionX;
    int pelletY = gunY + pelletOffsetCorrectionY;
    int rotation = 0;

    float deltaTime;
    float time = 0;

    int mouseX = 0, mouseY = 0;
    int offsetCorrectionX = 0, offsetCorrectionY = 0;
    double rotationAngle;
    double angleOffsetCorrection = 51;

    SDL_Texture* texture = nullptr;


    bool textureLoaded = false;


};

#endif // Gun_hpp