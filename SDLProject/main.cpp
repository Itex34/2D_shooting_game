#include "Game.hpp"
#include "Ball.hpp"
#include "Gun.hpp"
#include "SDL.h"
#include "Pellet.hpp"
#include "windows.h"
#include <cstdlib>

Game* game = nullptr;
Ball* ball = nullptr;
Gun* gun = nullptr;

int main(int argc, char* argv[])
{	
	const float targetFPS = 60.0f; // Target frame rate (in frames per second)
	const float maxFrameTime = 1.0f / targetFPS; // Maximum allowed time per frame (in s
	Uint32 prevTicks = SDL_GetTicks();
	const float dt = 1000.0f / targetFPS; // Desired time per frame (in milliseconds)
	int windowWidth = 1300;
	int windowHeight = 700;



	ball = new Ball();
	game = new Game();
	gun = new Gun();


	game->init("GameWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, false);

	while (game->running())
	{

		Uint32 currentTicks = SDL_GetTicks();
		float deltaTime = (currentTicks - prevTicks) / 1000.0f; // Convert milliseconds to seconds
		prevTicks = currentTicks;

		game->handleEvents();
		game->update();

		ball->update(windowWidth, windowHeight, deltaTime);
		
		gun->update(windowWidth, windowHeight);

		ball->render(game->getRenderer(), -20, 30);
		ball->render(game->getRenderer(), 100, 30);
		ball->render(game->getRenderer(), 300, 30);
		ball->render(game->getRenderer(), 800, 30);
		
		gun->render(game->getRenderer(), windowWidth, windowHeight);
		SDL_RenderPresent(game->getRenderer());

		game->render();
		

		Uint32 frameTicks = SDL_GetTicks() - currentTicks;
		if (frameTicks < maxFrameTime * 1000.0f) {
			SDL_Delay((Uint32)((maxFrameTime * 1000.0f) - frameTicks));
		}
		if (ball->isOutOfBoundaries == true) {
			ball->deleteTexture(ball->getTexture());
		}
	}

	gun->cleanup();
	game->clean();
	ball->deleteTexture(ball->getTexture());
	delete ball;
	delete game;
	return 0;

}