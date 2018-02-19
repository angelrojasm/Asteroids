#pragma once
#include "Vector2.h"
#include <vector>
class Entity
{
protected:

	Vector2 PositionVector;
	float OrientationAngle;
	float mass;
	std::vector<Vector2> RenderingContainer;

public:

	virtual void Render(void);
	float warp(float, int, int);
	void setOrientationAngle(float);
	float getOrientationAngle(void);
	Entity();
	~Entity();
};

