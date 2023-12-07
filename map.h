#pragma once

#include <string>
#include "juego.hpp"
class map
{
public:
	map();
	~map();

	static void LoadMap(std::string path, int sizeX, int sizeY);

private:
	
};