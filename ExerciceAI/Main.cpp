#include "LightEngine/GameManager.h"
#include "MainScene.h"

int main()
{
    GameManager* pInstance = GameManager::Get();

    pInstance->CreateWindow(1280, 720, "SampleScene");
	
    pInstance->LaunchScene<MainScene>();

    return 0;
}

