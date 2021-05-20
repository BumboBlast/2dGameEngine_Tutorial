#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#pragma once

#include <SDL.h>



class GameObject {



public:
	GameObject(const char* texturesheet, SDL_Renderer* objectRenderer);
	~GameObject();



	void update();		
	void render();

private:

	int xpos;
	int ypos;

	SDL_Texture* objectTexture;
	SDL_Rect srcRect, dstRect;

	SDL_Renderer* gRenderer;


};




#endif

