#include "Game.h"
#include "Sprite.h"



SDL_Texture* playerTexture = NULL;
SDL_Rect     srcRect, dstRect;


Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int screenWidth, int screenHeight, bool fullscreen)
{	
	Uint32 flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("SDL could not be initialized, ERR: %s\n", SDL_GetError());
		isRunning = false;
	}
	else {

		gWindow = SDL_CreateWindow(title, xpos, ypos, screenWidth, screenHeight, flags);
		if (gWindow == NULL) {
			printf("window could not be created, ERR: %s\n", SDL_GetError());
			isRunning = false;
		}
		else {

			gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
			if (gRenderer == NULL) {
				printf("renderer could not be created, ERR: %s\n", SDL_GetError());
				isRunning = false;
			}
			else {

				SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
				isRunning = true;

				Sprite player;
				playerTexture = player.getPlayerTexture("sprites/player.png", gRenderer);
				if (playerTexture == NULL) {
					printf("player texture could not be created, ERR: %s\n", IMG_GetError());
				}
			}
		}
	}	
}

void Game::handleEvents()
{

	SDL_Event gEvent;

	SDL_PollEvent(&gEvent);
	switch (gEvent.type){
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}



void Game::update()
{
	
	debugCounter++;

	dstRect.w =	64;
	dstRect.h = 64;

	dstRect.x = debugCounter;

}


void Game::render()
{
	//clear what is in the renderer's buffer
	if (SDL_RenderClear(gRenderer) == -1) {
		printf("RenderClear returned error, ERR: %s\n", SDL_GetError());
		isRunning = false;			//crash the game ?? lol
	}


	/*
	* add stuff to render
	* 
	*/


	SDL_RenderCopy(gRenderer, playerTexture, NULL, &dstRect);






	SDL_RenderPresent(gRenderer);
}


void Game::clean()
{


	SDL_DestroyWindow(gWindow);
	SDL_DestroyRenderer(gRenderer);
	SDL_Quit();
}
