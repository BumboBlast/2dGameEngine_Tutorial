#include "Map.h"
#include "TextureManager.h"




int level1[20][25] = {

	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	
};


//initialize a map
Map::Map()
{
	dirt	= TextureManager::loadTexture("sprites/dirt.png");
	grass	= TextureManager::loadTexture("sprites/grass.png");
	water	= TextureManager::loadTexture("sprites/water.png");

	LoadMap(level1);

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 32;
	srcRect.h = 32;

	dstRect.x = 0;
	dstRect.y = 0;
	dstRect.w = 32;
	dstRect.h = 32;
}



Map::~Map()
{

}



void Map::LoadMap(int mapArray[20][25])
{
	for (int row = 0; row < 20; row++) {
		for (int column = 0; column < 25; column++) {


			gMap[row][column] = mapArray[row][column];
		}
	}
}



void Map::drawMap()
{

	int type = 0;

	for (int row = 0; row < 20; row++) {
		for (int column = 0; column < 25; column++) {


			type = gMap[row][column];

			dstRect.x = column	* 32;
			dstRect.y = row		* 32;

			switch (type) {
			case 0:
				TextureManager::draw(water, srcRect, dstRect);
				break;
			case 1:
				TextureManager::draw(dirt, srcRect, dstRect);
				break;
			case 2:
				TextureManager::draw(grass, srcRect, dstRect);
				break;
			}
		}
	}
}
