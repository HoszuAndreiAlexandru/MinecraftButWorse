#pragma once
#include <ResourceManager/ResourceManager.hpp>

#include <Window/InputManager.hpp>
#include <Physics/PhysicsManager.hpp>
#include <Game/GameScene.hpp>
#include <Audio/AudioManager.hpp>

class GameManager {
public:
	ResourceManager* resourceManager = nullptr;

	InputManager* inputManager = nullptr;
	PhysicsManager* physicsManager = nullptr;
	GameScene* currentScene = nullptr;
	AudioManager* audioManager = nullptr;

	GameManager();
	~GameManager();

	void updateCurrentSceneLogic(double deltaTime);

	void unloadCurrentScene();
	void loadInitialScene();
	void loadScene(std::string sceneName);
};