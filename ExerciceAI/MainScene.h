#pragma once

namespace sf { class Event; }
class Zombie;
class Plant;

#include <vector>
#include <array>
#include <SFML/Graphics/Rect.hpp>
#include "LightEngine/Scene.h"


class MainScene : public Scene
{
public:
    void Initialize() override;
    void HandleInput(const sf::Event& event) override;
    void Update() override;

protected:
    std::vector<Zombie*> mZombies = {};
    std::array<Plant*, 6> mPlants = {};
    std::array<sf::FloatRect, 6> mLanes = {};
};
