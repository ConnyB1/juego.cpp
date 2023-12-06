#pragma once

#include "juego.hpp"

class Texturemanager
{
public:
	static SDL_Texture* LoadTexture(const char* fileName);
};