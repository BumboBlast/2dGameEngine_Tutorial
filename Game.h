#ifndef GAME_H
#define GAME_H
#pragma once
#include <SDL.h>
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

private:
	bool isRunning;
	SDL_Window*		gWindow		= NULL;
	SDL_Renderer*	gRenderer	= NULL;

	int debugCounter = 0;
};





#endif

