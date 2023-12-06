#include "juego.hpp"

juego *jueg = nullptr;

int main(int argc, char* args[])
{

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 framestart;
	int frametime;

	jueg = new juego();
	jueg->init("Juego", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false); //true para pantalla completa

	while (jueg->running())
	{

		framestart = SDL_GetTicks();

		jueg->handleevent();
		jueg->update();
		jueg->render();

		frametime = SDL_GetTicks() - framestart;

		if (frameDelay > frametime)
		{
			SDL_Delay(frameDelay - frametime);
		}
	}

	jueg->clean();
	return 0;
}