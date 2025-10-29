#pragma once
#include "AbstractRenderer/AbstractRenderer.hpp"
#include "OpenGL/OpenGLRenderer.hpp"

class RenderManager {
public:
	RenderAPI api;
	AbstractRenderer* currentRenderer = nullptr;

	RenderManager(RenderAPI renderApi = RenderAPI::OpenGL);
	~RenderManager();
	void renderFrame(double deltaTime, GameManager& gameManager);
};