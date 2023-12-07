#pragma once
#include "componentes.h"
#include "vector2d.h"

class transformcomponent : public component
{

public:

	Vector2D position;
	Vector2D velocity;

	int altura = 32;
	int ancho = 32;
	int scale = 1;

	int speed = 3;
	transformcomponent()
	{
		position.x = 0.0f;
		position.y = 0.0f;
	}

	transformcomponent(float x, float y)
	{
		position.x = x;
		position.y = y;
	}

	void init() override
	{
		velocity.x = 0;
		velocity.y = 0;
	}

	void update() override
	{
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}

};