#pragma once

#include "juego.hpp"
#include "ECS.h"
#include "componentes.h"

class controles : public component
{
public:
	transformcomponent* transform;

	void init() override
	{
		transform = &entity->getcomponent<transformcomponent>();
	}
	void update() override
	{
		if (juego::event.type == SDL_KEYDOWN)
		{
			switch (juego::event.key.keysym.sym)
			{
			case SDLK_w:
				transform->velocity.y = -1;
				break;
			case SDLK_a:
				transform->velocity.x = -1;
				break;
			case SDLK_d:
				transform->velocity.x = 1;
				break;
			case SDLK_s:
				transform->velocity.y = 1;
				break;

			default:
				break;
			}
		}
		if (juego::event.type == SDL_KEYUP)
		{
			switch (juego::event.key.keysym.sym)
			{
				case SDLK_w:
					transform->velocity.y = 0;
					break;
				case SDLK_a:
					transform->velocity.x = 0;
					break;
				case SDLK_d:
					transform->velocity.x = 0;
					break;
				case SDLK_s:
					transform->velocity.y = 0;
					break;

				default:
					break;
				
			}
		}
	}
};