#ifndef GAME_H
#define GAME_H
#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "StandardForward.h"



class Game {

public:
	Game(); 
	~Game(); 

	void init(const char* title, int xpos, int ypos, int screenWidth, int screenHeight, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }


	static SDL_Renderer* gRenderer;

private:
	bool isRunning;
	SDL_Window*		gWindow		= NULL;

	int debugCounter = 0;
};





#endif

