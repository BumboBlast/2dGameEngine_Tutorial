#ifndef SPRITE_H
#define SRPITE_H
#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "StandardForward.h"



class Sprite {
private:

	
	SDL_Texture* playerTexture = NULL;

public:
	
	SDL_Texture* getPlayerTexture(std::string filepath, SDL_Renderer* gRenderer);
	
};






#endif
