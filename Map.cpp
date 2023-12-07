#include "map.h"
#include "juego.hpp"
#include <fstream>

map::map()
{
	
}

map::~map()
{

}

void map::LoadMap(std::string path, int sizeX, int sizeY)
{
	char tile;
	std::fstream mapfile;
	mapfile.open(path);

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			mapfile.get(tile);
			juego::AddTile(atoi(&tile), x * 32, y * 32);
			mapfile.ignore();
		}
	}

	mapfile.close();
}

