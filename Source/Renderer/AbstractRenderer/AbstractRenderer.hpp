#pragma once
#include "../../Game/GameManager.hpp"

enum class RenderAPI {
	OpenGL,
	DirectX,
	Vulkan,
	Metal
};

class AbstractRenderer {
public:
	RenderAPI type = RenderAPI::OpenGL; // Default renderer

	virtual ~AbstractRenderer() = default;

	virtual void initialize() = 0;
	virtual void renderFrame(double deltaTime, GameManager& gameManager) = 0;
	virtual void shutdown() = 0;
};