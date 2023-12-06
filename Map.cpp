#include "map.h"
#include "Texturemanager.h"

int lvl1[20][25] = {0,0}

map::map()
{
	dirt = Texturemanager::LoadTexture("assets/dirt.png");
	grass = Texturemanager::LoadTexture("assets/grass.png");
	water = Texturemanager::LoadTexture("assets/water.png");
}

void map::LoadMap()
{}

void map::DrawMap()
{}