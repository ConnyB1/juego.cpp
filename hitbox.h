#pragma once

#include <string>
#include "SDL.h"
#include "componentes.h"

class hitbox : public component
{
	SDL_Rect collider;
	std::string tag;
	
	transformcomponent* transform;

	void init() override
	{
		if (!entity->hascomponent<transformcomponent>());
		{
			entity->addcomponent<transformcomponent>();
		}
		transform = &entity->getcomponent<transformcomponent>();
	}

	void update() override
	{
		collider.x = transform->position.x;
		collider.y = transform->position.y;
		collider.w = transform->ancho * transform->scale;
		collider.h = transform->altura * transform->scale;
	}
};