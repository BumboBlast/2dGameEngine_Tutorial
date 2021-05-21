#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#pragma once

#include "Game.h"



class GameObject {



public:
	GameObject(const char* texturesheet, int initialposition_x, int initialposition_y);
	~GameObject();



	void update();		
	void render();

private:

	int xpos;
	int ypos;

	SDL_Texture* objectTexture;
	SDL_Rect srcRect, dstRect;



};




#endif

