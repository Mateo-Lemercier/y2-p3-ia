#include <iostream>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "LightEngine/Debug.h"
#include "Zombie.h"
#include "Plant.h"
#include "MainScene.h"



void MainScene::Initialize()
{
    for (int i = 0; i < 6; i++)
    {
        mPlants[i] = CreateEntity<Plant>(25.0f, sf::Color::Green);
        mPlants[i]->SetPosition(60.0f, static_cast<float>(60+110*i));

        mLanes[i].left = 40.0f;
        mLanes[i].top = static_cast<float>(40+110*i);
        mLanes[i].width = 1200.0f;
        mLanes[i].height = 90.0f;
    }
}

void MainScene::HandleInput(const sf::Event& event)
{
    if (event.type != sf::Event::EventType::MouseButtonPressed)
        return;

    if (event.mouseButton.button == sf::Mouse::Button::Left)
    {
        for (int i = 0; i < 6; i++)
        {
            sf::FloatRect const& laneRect = mLanes[i];
            if (laneRect.contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
            {
                sf::Vector2f const zombiePosition(1282.0f, laneRect.top+laneRect.height*0.5f);
                Zombie* const pZombie = CreateEntity<Zombie>(30.0f, sf::Color::Red);
                pZombie->SetPosition(zombiePosition.x, zombiePosition.y, 0.0f, 0.5f);
                pZombie->GoToDirection(mPlants[i]->GetPosition().x, zombiePosition.y, 20.0f);
                mZombies.push_back(pZombie);
            }
        }
    }
}

void MainScene::Update()
{
    for (sf::FloatRect const& rectangle : mLanes)
        Debug::Get()->DrawRectangle(rectangle.left, rectangle.top, rectangle.width, rectangle.height, sf::Color::White);

    for (Zombie const* pZombie : mZombies)
    {
        for (Plant* pPlant : mPlants)
        {
            if (pZombie->IsColliding(pPlant))
            {
                // how to destroy ?
            }
        }
    }
}
