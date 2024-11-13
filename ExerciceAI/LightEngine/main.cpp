#include "GameManager.h"
#include "SampleScene.h"

int main()
{
    GameManager* pInstance = GameManager::Get();

    pInstance->CreateWindow(1280, 720, "SampleScene");
	
    pInstance->LaunchScene<SampleScene>();

    return 0;
}

