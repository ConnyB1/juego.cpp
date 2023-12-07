#pragma once

#include "ECS.h"
#include "transformcomponent.h"
#include "Spritecomponent.h"
#include "SDL.h"

class tilecomponent : public component
{
public:
    transformcomponent* transform;
    spritecomponent* sprite;

    SDL_Rect tileRect;
    int tileID;
    const char* path;  // Cambiado a const char* o std::string

    tilecomponent() = default;

    tilecomponent(int x, int y, int w, int h, int id)
    {
        tileRect.x = x;
        tileRect.y = y;
        tileRect.w = w;
        tileRect.h = h;
        tileID = id;

        switch (tileID)
        {
        case 1:
            path = "assets/water.png";
            break;
        case 2:
            path = "assets/dirt.png";
            break;
        case 3:
            path = "assets/grass.png";
            break;
        default:
            break;
        }
    }

    void init() override
    {
        entity->addcomponent<transformcomponent>((float)tileRect.x, (float)tileRect.y, tileRect.w, tileRect.h, 1);
        transform = &entity->getcomponent<transformcomponent>();

        entity->addcomponent<spritecomponent>(path);
        sprite = &entity->getcomponent<spritecomponent>();
    }
};
