#pragma once

class PhysicsManager {
public:
	PhysicsManager();
	~PhysicsManager();

	void stepSimulation(double deltaTime);
};