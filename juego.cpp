#include "juego.hpp"
#include "Texturemanager.h"
#include "Objetos.h"

objetos* player;
objetos* profesor;

SDL_Renderer* juego::renderer = nullptr;

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
	player = new objetos("assets/player.png", 0, 0);
	profesor = new objetos("assets/profesor.png", 50, 50);
		
}

void juego::handleevent()
{
	SDL_Event event;
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
	player->update();
	profesor->update();
}

void juego::render()
{
	SDL_RenderClear(renderer);
	player->render();
	profesor->render();
	SDL_RenderPresent(renderer);

}

void juego::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}