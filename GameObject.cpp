#include "GameObject.h"
#include "TextureManager.h"

/*
* this instantiates a new sprite onto the screen, with a starting position
*/
GameObject::GameObject(const char* texturesheet, SDL_Renderer* objectRenderer, int initialposition_x, int initialposition_y)
{
	/*
	* when we make a copy of our game object, we need to assign the renderer and our texture. Renderer first
	*/

	gRenderer		= objectRenderer;
	objectTexture	= TextureManager::loadTexture(texturesheet, objectRenderer);

	xpos = initialposition_x;
	ypos = initialposition_y;
}


void GameObject::update()
{
	xpos++;
	ypos++;



	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	dstRect.x = xpos;
	dstRect.y = ypos;
	dstRect.w = srcRect.w * 2; 
	dstRect.h = srcRect.h * 2;
}

void GameObject::render()
{

	SDL_RenderCopy(gRenderer, objectTexture, &srcRect, &dstRect);	//this "paints" part of the texture we are looking at to the scene.
}