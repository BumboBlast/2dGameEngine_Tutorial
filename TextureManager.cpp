#include "TextureManager.h"

SDL_Texture* TextureManager::loadTexture(const char* filepath, SDL_Renderer* gRenderer)
{
	SDL_Surface* playerSurface = IMG_Load(filepath);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(gRenderer, playerSurface);
	SDL_FreeSurface(playerSurface);
	return texture;
}