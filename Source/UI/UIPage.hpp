#pragma once
#include "UIElement.hpp"

class UIPage {
public:
	std::vector<std::unique_ptr<UIElement>> elements;

	virtual ~UIPage() = default;

	virtual void onEnter() {};
	virtual void onExit() {};

	void update(double dt)
	{
		for (auto& e : elements)
		{
			e->update(dt);
		}
	}

	void draw()
	{
		for (auto& e : elements)
		{
			e->draw();
		}
	}

	virtual bool blocksSceneInput() const { return true; }
	virtual bool blocksSceneUpdate() const { return true; }
};