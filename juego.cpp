#include "juego.hpp"
#include "Texturemanager.h"
#include "componentes.h"
#include "map.h"
#include "vector2d.h"

map* mapa;
manager Manager;

SDL_Renderer* juego::renderer = nullptr;
SDL_Event juego::event;

auto& Player(Manager.addentity());

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
		std::cout << "Subsystems Initialised!..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, ancho, altura, flags);
		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}
		isrunnig = true;
		}
	else
	{
		isrunnig = false;
	}
	mapa = new map();
	Player.addcomponent<transformcomponent>();
	Player.addcomponent<spritecomponent>("assets/player.png");
	Player.addcomponent<controles>();
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
	
}

void juego::render()
{
	SDL_RenderClear(renderer);
	mapa->DrawMap();
	Manager.draw();
	SDL_RenderPresent(renderer);

}

void juego::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}