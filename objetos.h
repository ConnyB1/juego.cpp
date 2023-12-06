#pragma once
#include "juego.hpp"
class objetos
{
public:
	objetos(const char* texturesheet, int x, int y);
	~objetos();

	void update();
	void render();

private:

	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	
};