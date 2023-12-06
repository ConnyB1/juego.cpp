#pragma once

#include "juego.hpp"

class map
{
public:
	map();
	~map();

	void LoadMap(int arr[20][25]);
	void DrawMap();

private:
	SDL_Rect src, dest;
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;
	
	int Map[20][25];
};