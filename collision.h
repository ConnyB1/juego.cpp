#pragma once

#include <SDL.h>

class hitbox;

class collision
{
public:
	static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
	static bool AABB(const hitbox& colA, const hitbox& colB);
};