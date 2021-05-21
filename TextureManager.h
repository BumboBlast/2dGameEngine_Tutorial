#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#pragma once
#include "Game.h"

class TextureManager {

private:





public:
	/*
	* we dont want to instantiate an object each time we call this function, so we make it static
	*/

	static SDL_Texture* loadTexture(const char* filename);


	static void draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst);
};












#endif