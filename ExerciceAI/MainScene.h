#pragma once
#include "Zombie.h"
#include "Plant.h"
#include "LightEngine/Scene.h"


class MainScene : public Scene
{
public:
    void Initialize() override;
    void HandleInput(const sf::Event& event) override;
    void Update() override;

protected:
    Zombie* pZombie;
    Plant* pPlant;
};
