#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* player;

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

				player = new GameObject("sprites/player.png", gRenderer);
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
	player->update();
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


	player->render();



	SDL_RenderPresent(gRenderer);			//this function is like SDL_UpdateWindowSurface or whatever its called
}


void Game::clean()
{


	SDL_DestroyWindow(gWindow);
	SDL_DestroyRenderer(gRenderer);
	SDL_Quit();
}
