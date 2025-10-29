#pragma once
#include "pch.h"

#include "Window/Window.hpp"
#include "Renderer/RenderManager.hpp"

int main(void)
{
	Window* window = new Window("OpenGL Window", 1280, 720);
	GameManager* gameManager = new GameManager();
	RenderManager* renderManager = new RenderManager();

	gameManager->loadInitialScene();

	using clock = std::chrono::high_resolution_clock;
	auto lastTime = clock::now();

	while (!glfwWindowShouldClose(window->glfwWindow))
	{
		auto currentTime = clock::now();
		std::chrono::duration<double> elapsed = currentTime - lastTime;
		lastTime = currentTime;
		double deltaTime = elapsed.count();

		glfwSwapBuffers(window->glfwWindow);
		glfwPollEvents();
		gameManager->updateCurrentSceneLogic(deltaTime);
		renderManager->renderFrame(deltaTime, *gameManager);
	}

	delete renderManager;
	delete gameManager;
	delete window;

	return 0;
}