#pragma once

class UIElement {
public:
	virtual ~UIElement() = default;

	virtual void update(double dt) {}
	virtual void draw() = 0;
	virtual void handleInput() {}
};