#include "Texturemanager.h"

SDL_Texture* Texturemanager::LoadTexture(const char* texture)
{
	SDL_Surface* tempsurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(juego::renderer, tempsurface);
	SDL_FreeSurface(tempsurface);

	return tex; 
}