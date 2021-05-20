#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#pragma once
#include "StandardForward.h"
#include <SDL.h>
#include <SDL_image.h>

class TextureManager {

private:





public:
	/*
	* we dont want to instantiate an object each time we call this function, so we make it static
	*/

	static SDL_Texture* loadTexture(const char* filename, SDL_Renderer* gRenderer);
};












#endif