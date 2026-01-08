#pragma once
#include "pch.h"
#include "GameManager.hpp"

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

void GameManager::updateCurrentSceneLogic(double deltaTime)
{
	if (!currentScene) return;

	// Interpret input state and all input events
	inputManager->update();

	// Update all current scene physics
	physicsManager->stepSimulation(deltaTime);

	// Update all game objects logic
	currentScene->updateLogic(deltaTime);

	// Handle audio updates
	audioManager->update(deltaTime);
}

void GameManager::unloadCurrentScene()
{
	if (!currentScene) return;
	// Clean up current scene resources
	delete currentScene;
	currentScene = nullptr;
}

void GameManager::loadInitialScene()
{
	unloadCurrentScene();
	// Load the intro scene
}

void GameManager::loadScene(std::string sceneName)
{
	// Unload current scene
	unloadCurrentScene();
	// Load new scene by name

}