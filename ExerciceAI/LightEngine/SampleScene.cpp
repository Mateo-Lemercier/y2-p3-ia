#include "SampleScene.h"

#include "DummyEntity.h"

#include "Debug.h"

void SampleScene::Initialize()
{
	pEntity1 = CreateEntity<DummyEntity>(100, sf::Color::Red);
	pEntity1->SetPosition(100, 100);

	pEntity2 = CreateEntity<DummyEntity>(50, sf::Color::Green);
	pEntity2->SetPosition(500, 500);

	pEntitySelected = nullptr;
}

void SampleScene::HandleInput(const sf::Event& event)
{
	if (event.type == sf::Event::EventType::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Button::Left)
		{
			if (pEntitySelected == nullptr) return;
			pEntitySelected->GoToPosition(event.mouseButton.x, event.mouseButton.y, 500.0f);
			mIsHoldingLeft = true;
		}
		
		else if (event.mouseButton.button == sf::Mouse::Button::Right)
		{
			TrySetSelectedEntity(pEntity1, event.mouseButton.x, event.mouseButton.y);
			TrySetSelectedEntity(pEntity2, event.mouseButton.x, event.mouseButton.y);
		}
	}
		else if (event.type == sf::Event::EventType::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Button::Left)
	{
		mIsHoldingLeft = false;
	}
	
	if (event.type == sf::Event::EventType::MouseMoved && mIsHoldingLeft && pEntitySelected != nullptr)
	{
		pEntitySelected->GoToPosition(event.mouseMove.x, event.mouseMove.y, 500.0f);
	}
}

void SampleScene::TrySetSelectedEntity(DummyEntity* pEntity, int x, int y)
{
	if (pEntity->IsInside(x, y) == false)
		return;

	pEntitySelected = pEntity;
}

void SampleScene::Update()
{
	
	if(pEntitySelected != nullptr)
	{
		sf::Vector2f position = pEntitySelected->GetPosition(0.5f, 0.5f);
		Debug::DrawCircle(position.x, position.y, 10, sf::Color::Blue);
	}
}