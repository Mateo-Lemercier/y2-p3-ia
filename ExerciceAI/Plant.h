#pragma once
#include "LightEngine/Entity.h"

class Plant : public Entity
{
public:
    Plant(float radius, const sf::Color& color);

protected:
    char mHealth;
};
