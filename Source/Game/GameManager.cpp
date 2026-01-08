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

	// Update UI elements
	uiManager->update(deltaTime);

	// If UI does not block scene input, handle scene input
	if (!uiManager->blocksSceneInput())
	{
		currentScene->handleInput();
	}

	// If UI does not block scene update, update scene logic
	if (!uiManager->blocksSceneUpdate())
	{
		physicsManager->stepSimulation(deltaTime);
		currentScene->update(deltaTime);
	}

	audioManager->update(deltaTime);
}

void GameManager::unloadCurrentScene()
{
	if (!currentScene) return;
	// Clean up current scene resources

}

void GameManager::loadInitialScene()
{
	// Loads the first scene (main menu)

	// Delete all current scene resources
	this->unloadCurrentScene();

	// Add UI + logic for main menu
}

void GameManager::loadScene(std::string sceneName)
{
	// Unload current scene
	unloadCurrentScene();

	// Load new scene by its name
}