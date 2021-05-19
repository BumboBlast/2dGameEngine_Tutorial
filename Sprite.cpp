#include "Sprite.h"

/*
* filepath -->> texture pointer to the sprite
*/
SDL_Texture* Sprite::getPlayerTexture(std::string filepath, SDL_Renderer* gRenderer)
{
	SDL_Surface* playerSurface = IMG_Load(filepath.c_str());
	playerTexture = SDL_CreateTextureFromSurface(gRenderer, playerSurface);
	SDL_FreeSurface(playerSurface);
	return playerTexture;
}