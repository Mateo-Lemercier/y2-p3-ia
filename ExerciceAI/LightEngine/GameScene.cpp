#include "GameScene.h"

#include "Plant.h"
#include "Zombie.h"
#include "Debug.h"

void GameScene::Initialize()
{
	int width = GetWindowWidth();
	int height = GetWindowHeight();

	float plantRadius = 50.f;
	float plantHeight = plantRadius * 2;
	float spaceBetweenPlants = 20;

	float totalHeight = (spaceBetweenPlants * 2) + (plantHeight * 3);
	float spacing = height - totalHeight;

	float startX = plantRadius * 2;
	float startY = plantRadius + (spacing / 2);

	for (int i = 0; i < 3; i++) 
	{
		mpPlants[i] = CreateEntity<Plant>(plantRadius, sf::Color::Green);
		mpPlants[i]->SetPosition(startX, startY, 0.5f, 0.5f);
		mpPlants[i]->SetAreaIndex(i);

		int xMin = startX + plantHeight;
		int yMin = startY - plantRadius;
		int xMax = width;
		int yMax = startY + plantRadius;

		mAreas[i] = { xMin, yMin, xMax, yMax };

		startY += plantHeight + spaceBetweenPlants;
	}
}

void GameScene::Update()
{
	for (int i = 0; i < 3; i++)
	{
		const AABB& aabb = mAreas[i];

		Debug::DrawRectangle(aabb.xMin, aabb.yMin, aabb.xMax - aabb.xMin, aabb.yMax - aabb.yMin, sf::Color::Red);
	}

	for (int i = 0; i < 3; i++) 
	{
		for (auto it = mZombies[i].begin(); it != mZombies[i].end();)
		{
			if ((*it)->ToDestroy() == false) 
			{
				it++;
				continue;
			}

			it = mZombies[i].erase(it);
		}
	}
}

int GameScene::GetClickedArea(int x, int y) const
{
	for (int i = 0; i < 3; i++)
	{
		const AABB* aabb = &mAreas[i];

		if (x >= aabb->xMin && x <= aabb->xMax && y >= aabb->yMin && y <= aabb->yMax)
			return i;
	}

	return -1;
}

void GameScene::HandleInput(const sf::Event& event)
{
	if (event.type != sf::Event::EventType::MouseButtonPressed)
		return;

	int index = GetClickedArea(event.mouseButton.x, event.mouseButton.y);

	if(index == -1)
		return;

	const AABB* clickedArea = &mAreas[index];

	int y = clickedArea->yMin + (clickedArea->yMax - clickedArea->yMin) / 2;

	Zombie* pZombie = CreateEntity<Zombie>(25, sf::Color::Red);
	pZombie->SetPosition(event.mouseButton.x, y, 0.5f, 0.5f);

	mZombies[index].push_back(pZombie);
}

bool GameScene::IsZombieInArea(int index) const
{
	_ASSERT(index >= 0 && index < 3);

	return mZombies[index].size() > 0;
}