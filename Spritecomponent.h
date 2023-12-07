#pragma once

#include "componentes.h"
#include "SDL.h"
#include "Texturemanager.h"

class spritecomponent : public component
{
private:
	transformcomponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

public:
	spritecomponent() = default;
	spritecomponent(const char* path)
	{
		settext(path);
	}
	~spritecomponent()
	{
		SDL_DestroyTexture(texture);
	}



	void settext(const char* path)
	{
		texture = Texturemanager::LoadTexture(path);
	}

	void init() override
	{

		transform = &entity->getcomponent<transformcomponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->ancho;
		srcRect.h = transform->altura;
		
	}

	void update() override
	{
		destRect.x = (int)transform->position.x;
		destRect.y = (int)transform->position.y;
		destRect.w = transform->ancho * transform->scale;
		destRect.h = transform->altura * transform->scale;
	}
	void draw() override
	{
		Texturemanager::Draw(texture, srcRect, destRect);
	}


};