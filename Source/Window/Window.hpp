#pragma once

class Window{
	public:
		std::string title = "";
		int height = 0;
		int width = 0;
		GLFWwindow* glfwWindow = nullptr;

		Window(const char* windowTitle, int windowWidth, int windowHeight);
		~Window();
};