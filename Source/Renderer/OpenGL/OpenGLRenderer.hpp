#pragma once
#include "../AbstractRenderer/AbstractRenderer.hpp"

class OpenGLRenderer : public AbstractRenderer {
public:
    OpenGLRenderer() { type = RenderAPI::OpenGL; }

    void initialize() override;
    void renderFrame(double deltaTime, GameManager& gameManager) override;
    void shutdown() override;
};