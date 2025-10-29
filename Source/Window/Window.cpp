#pragma once
#include "pch.h"
#include "Window.hpp"

Window::Window(const char* windowTitle, int windowWidth, int windowHeight)
{
	title = windowTitle;
	width = windowWidth;
	height = windowHeight;

	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		(void)getchar();
		return;
	}

	glfwWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if (glfwWindow == NULL)
	{
		fprintf(stderr, "Failed to open GLFW window.");
		(void)getchar();
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(glfwWindow);

	glViewport(0, 0, width, height);
}

Window::~Window()
{
	if (glfwWindow != nullptr)
	{
		glfwDestroyWindow(glfwWindow);
		glfwTerminate();
	}
}