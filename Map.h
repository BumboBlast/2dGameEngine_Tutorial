#ifndef MAP_H
#define MAP_H
#pragma once
#include "Game.h"




class Map {


public:

	Map();
	~Map();

	void LoadMap(int mapArray[20][25]);
	void drawMap();
private:


	SDL_Rect srcRect, dstRect;

	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	//Game map
	int gMap[20][25];
};


#endif