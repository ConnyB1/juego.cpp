#ifndef juego_hpp
#define juego_hpp

#include <SDL.h>
#include "SDL_image.h"
#include <iostream>

class juego
{
public:
	juego();
	~juego();

	void init(const char* title, int xpos, int ypos, int ancho, int altura, bool fullscreen);
	void handleevent();
	void update();
	void render();
	void clean();

	bool running() { return isrunnig; }
	static SDL_Renderer* renderer;
	static SDL_Event event;

private:
	int cnt = 0;
	bool isrunnig;
	SDL_Window* window;
};

#endif /*juego.h*/