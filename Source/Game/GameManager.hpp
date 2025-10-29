#pragma once
#include "GameScene.hpp"
#include "../ResourceManager/ResourceManager.hpp"

class GameManager {
public:
	ResourceManager* resourceManager = nullptr;

	GameScene* currentScene = nullptr;

	GameManager();
	void loadInitialScene();
	void updateCurrentSceneLogic(double deltaTime);
	~GameManager();
};