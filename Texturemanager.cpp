#include "Texturemanager.h"
#include <SDL_image.h>

SDL_Texture* Texturemanager::LoadTexture(const char* texture)
{
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(juego::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex; 
}

void Texturemanager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(juego::renderer, tex, &src, &dest);
}
