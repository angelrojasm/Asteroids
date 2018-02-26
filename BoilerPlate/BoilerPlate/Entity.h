#pragma once
#include "Vector2.h"
#include <vector>
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
class Entity
{
protected:

	Vector2 PositionVector;
	float OrientationAngle;
	float mass;
	std::vector<Vector2> RenderingContainer;
	Vector2 Acceleration;
	Vector2 Velocity;
	float Radius;
	bool Debugging;
	bool Collision;


	const int minWidthBorder = -568;
	const int maxWidthBorder = 568;
	const int minHeightBorder = -320;
	const int maxHeightBorder = 320;
	const float DistanceUnit = 10;


public:

	virtual void Render(void);
	virtual void Update(float);
	float warp(float, int, int);
	void setOrientationAngle(float);
	float getOrientationAngle(void);
	void setVelocity(Vector2);
	void AccumulateVelocity(float);
	Vector2 getVelocity(void);
	void MoveForward(void);
	void setDebugging(bool);
	bool getDebugging(void);
	void CreateEntityBounds(void);
	float getRadius(void);
	Vector2 getPositionVector(void);
	float EntityDistance(Entity);
	bool HasCollided(void);
	bool DetectCollision(Entity);
	void ChangePositions(float, float);

	Entity();
	~Entity();
};

