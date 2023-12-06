#include "objetos.h"
#include "Texturemanager.h"

objetos::objetos(const char* texturesheet, int x, int y)
{
	objTexture = Texturemanager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
}

void objetos::update()
{

	xpos++;
	ypos++;

	srcRect.h = 32;
	srcRect.w = 32;

	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}

void objetos::render()
{
	SDL_RenderCopy(juego::renderer, objTexture, &srcRect, &destRect);
}