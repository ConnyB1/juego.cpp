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
		position.Zero();
	}

	transformcomponent(int sc)
	{
		position.Zero();
		scale = sc;
	}

	transformcomponent(float x, float y)
	{
		position.Zero();
	}
	transformcomponent(float x, float y, int h, int w, int sc)
	{
		position.x = x;
		position.y = y;
		altura = h;
		ancho = w;
		scale = sc;
	}

	void init() override
	{
		velocity.Zero();
	}

	void update() override
	{
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}

};