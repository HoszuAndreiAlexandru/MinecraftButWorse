#pragma once
// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// Include GLEW and GLFW
#include "glew/glew.h"
#include "glfw/glfw3.h"

// Include GLM
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

// Include our logic
#include "Window/Window.hpp"
#include "Renderer/RenderManager.hpp"
#include <chrono>

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