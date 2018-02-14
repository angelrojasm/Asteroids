#pragma once
#include "Vector2.h"
#include "SDLEvent.hpp"
class Player
{


private:
	Vector2 PositionVector;
	bool IsThrusting;
	float OrientationAngle;
	float mass;

	

public:

	Player();
	~Player();

	void Render();

	void move(Vector2);
	float warp(float, int, int);
	void MoveForward(void);
	void RotateLeft	(void);
	void RotateRight(void); 
	bool getIsThrusting(void);
	void setIsThrusting(bool);
	void setOrientationAngle(float);
	float getOrientationAngle(void);


};

