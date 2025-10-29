#pragma once
#include "RenderManager.hpp"
#include <stdexcept>

#include "OpenGL/OpenGLRenderer.hpp"

using namespace std;

RenderManager::RenderManager(RenderAPI renderApi)
{
	api = renderApi;

	switch (api)
	{
	case RenderAPI::OpenGL:
		currentRenderer = new OpenGLRenderer();
		break;
	case RenderAPI::DirectX:
		throw std::runtime_error("DirectX renderer not implemented.");
		break;
	case RenderAPI::Vulkan:
		throw std::runtime_error("Vulkan renderer not implemented.");
		break;
	case RenderAPI::Metal:
		throw std::runtime_error("Metal renderer not implemented.");
		break;
	default:
		break;
	}
}

RenderManager::~RenderManager()
{
	currentRenderer->~AbstractRenderer();
}

void RenderManager::renderFrame(double deltaTime, GameManager& gameManager)
{
	// Placeholder for rendering logic based on the selected API
	switch (api)
	{
	case RenderAPI::OpenGL:
		currentRenderer->renderFrame(deltaTime, gameManager);
		break;
	case RenderAPI::DirectX:
		throw std::runtime_error("DirectX renderer not implemented.");
		break;
	case RenderAPI::Vulkan:
		throw std::runtime_error("Vulkan renderer not implemented.");
		break;
	case RenderAPI::Metal:
		throw std::runtime_error("Metal renderer not implemented.");
		break;
	default:
		break;
	}
}