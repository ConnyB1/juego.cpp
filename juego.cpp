#include "juego.hpp"
#include "Texturemanager.h"
#include "componentes.h"
#include "map.h"
#include "vector2d.h"
#include "collision.h"

map* mapa;
manager Manager;

SDL_Renderer* juego::renderer = nullptr;
SDL_Event juego::event;

std::vector<hitbox*> juego::colliders;

auto& Player(Manager.addentity());
auto& wall(Manager.addentity());



juego::juego()
{}
juego::~juego()
{}

void juego::init(const char* title, int xpos, int ypos, int ancho, int altura, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{

		window = SDL_CreateWindow(title, xpos, ypos, ancho, altura, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}
		isrunnig = true;
	}

	map::LoadMap("assets/p16x16.map", 16, 16);

	Player.addcomponent<transformcomponent>(2);
	Player.addcomponent<spritecomponent>("assets/player.png");
	Player.addcomponent<controles>();
	Player.addcomponent<hitbox>("player");

	wall.addcomponent<transformcomponent>(300.0f, 300.0f, 300, 20, 1);
	wall.addcomponent<spritecomponent>("assets/grass.png");
	wall.addcomponent<hitbox>("wall");
}

void juego::handleevent()
{
	

	SDL_PollEvent(&event);
	switch (event.type) 
	{
		case SDL_QUIT:
			isrunnig = false;
			break;
		default:
			break;
	}
}

void juego::update()
{
	Manager.update();
	Manager.refresh();
	
	for (auto cc  :  colliders)
	{
		collision::AABB(Player.getcomponent<hitbox>(), *cc);
	}
	
	
}

void juego::render()
{
	SDL_RenderClear(renderer);
	//mapa->DrawMap();
	Manager.draw();
	SDL_RenderPresent(renderer);

}

void juego::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void juego::AddTile(int id, int x, int y)
{
	auto& tile(Manager.addentity());
	tile.addcomponent<tilecomponent>(x, y, 32, 32, id);
	tile.addcomponent<hitbox>("tile");
}