#pragma once
#include "Vector2.h"
#include "SDLEvent.hpp"
class Player
{


private:
	Vector2 PositionVector;
	

public:

	Player();
	~Player();

	void Update(SDL_KeyboardEvent);
	void Render();

	void move(Vector2);
	float warp(float, int, int);
	void MoveForward(void);
	void RotateLeft	(void);
	void RotateRight(void); 



};

