#pragma once

#include <string>
#include "SDL.h"
#include "componentes.h"

class hitbox : public component
{
public:
	SDL_Rect collider;
	std::string tag;
	
	transformcomponent* transform;

	hitbox(std::string t)
	{
		tag = t;
	}

	void init() override
	{
		if (!entity->hascomponent<transformcomponent>())
		{
			entity->addcomponent<transformcomponent>();
		}
		transform = &entity->getcomponent<transformcomponent>();
	}

	void update() override
	{
		collider.x = static_cast<int>(transform->position.x);
		collider.y = static_cast<int>(transform->position.y);
		collider.w = transform->ancho * transform->scale;
		collider.h = transform->altura * transform->scale;
	}
};