#ifndef juego_hpp
#define juego_hpp

#include <SDL.h>
#include "SDL_image.h"
#include <iostream>
#include <vector>

class hitbox; //peuwb

class juego
{
public:
	juego();
	~juego();

	void init(const char* title, int xpos, int ypos, int ancho, int altura, bool fullscreen);
	void handleevent();
	void update();
	bool running() { return isrunnig; }
	void render();
	void clean();

	
	static SDL_Renderer* renderer;
	static SDL_Event event;
	static std::vector<hitbox*> colliders;

	static void AddTile(int id, int x, int y);

private:
	bool isrunnig = false;
	int cnt = 0;
	SDL_Window* window;
};

#endif /*juego.h*/