#include "Zombie.h"


Zombie::Zombie(float radius, const sf::Color& color):
    Entity(radius, color),
    mHealth(8) {}
