#pragma once

class GameManager {
public:

	GameManager();
	void loadInitialScene();
	void updateCurrentSceneLogic(double deltaTime);
	~GameManager();
};