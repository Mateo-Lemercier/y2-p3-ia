#include "MainScene.h"



void MainScene::Initialize()
{
    pZombie = CreateEntity<Zombie>(30.0f, sf::Color::Red);
    pZombie->SetPosition(100, 100);

    pPlant = CreateEntity<Plant>(25.0f, sf::Color::Green);
    pPlant->SetPosition(50, 50);
}

void MainScene::HandleInput(const sf::Event& event)
{
    //
}

void MainScene::Update()
{
    //
}
