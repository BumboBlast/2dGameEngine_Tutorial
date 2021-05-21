#include "TextureManager.h"

SDL_Texture* TextureManager::loadTexture(const char* filepath)
{
	SDL_Surface* playerSurface = IMG_Load(filepath);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::gRenderer, playerSurface);
	SDL_FreeSurface(playerSurface);
	return texture;
}


void TextureManager::draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst)
{


	SDL_RenderCopy(Game::gRenderer, texture, &src, &dst);
}