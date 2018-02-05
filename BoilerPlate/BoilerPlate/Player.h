#pragma once
#include "Vector2.h"
#include "SDLEvent.hpp"
class Player
{
public:

	
	Player();
	~Player();

	void Update(SDL_KeyboardEvent);
	void Render();

private:
	Vector2 PositionVector;



};

