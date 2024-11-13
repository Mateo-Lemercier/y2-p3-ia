#pragma once

#include "Scene.h"

class DummyEntity;

class SampleScene : public Scene
{
public:
	void Initialize() override;
	void HandleInput(const sf::Event& event) override;
	void Update() override;

private:
	void TrySetSelectedEntity(DummyEntity* pEntity, int x, int y);

	DummyEntity* pEntity1 = nullptr;
	DummyEntity* pEntity2 = nullptr;

	DummyEntity* pEntitySelected = nullptr;

	bool mIsHoldingLeft = false;
};


