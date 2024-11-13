#pragma once
#include "LightEngine/Entity.h"

class Zombie : public Entity
{
public:
    Zombie(float radius, const sf::Color& color);

protected:
    char mHealth;
};
