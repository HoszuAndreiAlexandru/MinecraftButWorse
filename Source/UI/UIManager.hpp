#pragma once
#include "pch.h"
#include "UIPage.hpp"

class UIManager {
public:
	std::vector<std::unique_ptr<UIPage>> pages;

	UIManager() = default;
	~UIManager() = default;

	void pushPage(std::unique_ptr<UIPage> page)
	{
		if (page)
		{
			if (!pages.empty())
			{
				pages.back()->onExit();
			}

			pages.push_back(std::move(page));
			pages.back()->onEnter();
		}
	}

	void popPage()
	{
		if (!pages.empty())
		{
			pages.back()->onExit();
			pages.pop_back();

			if (!pages.empty())
			{
				pages.back()->onEnter();
			}
		}
	}

	void update(double dt)
	{
		if (!pages.empty())
		{
			pages.back()->update(dt);
		}
	}

	bool hasActivePage() const
	{
		return !pages.empty();
	}

	bool blocksSceneInput() const
	{
		return hasActivePage() && pages.back()->blocksSceneInput();
	}

	bool blocksSceneUpdate() const
	{
		return hasActivePage() && pages.back()->blocksSceneUpdate();
	}
};