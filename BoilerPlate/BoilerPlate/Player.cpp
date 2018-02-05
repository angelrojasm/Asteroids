#include "Player.h"
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>


Player::Player()
{
	PositionVector = Vector2();
}


Player::~Player()
{
}

void::Player::Update(SDL_KeyboardEvent keyBoardEvent)
{

	switch (keyBoardEvent.keysym.scancode) {

	case SDL_SCANCODE_W:
		PositionVector.Y_coordinate+=10;
		break;

	case SDL_SCANCODE_A:
		PositionVector.X_coordinate-=10;
		break;

	case SDL_SCANCODE_S:
		PositionVector.Y_coordinate-=10;
		break;

	case SDL_SCANCODE_D:
		PositionVector.X_coordinate+=10;
		break;
	default:
		SDL_Log("%S was pressed.", keyBoardEvent.keysym.scancode);
		break;
	}
}
	void Player::Render()
	{
		glLoadIdentity();
		glTranslatef(PositionVector.X_coordinate, PositionVector.Y_coordinate, 0.0f);

		glBegin(GL_LINE_LOOP);
		glVertex2f(50 + PositionVector.X_coordinate, 50.0 + PositionVector.Y_coordinate);
		glVertex2f(50.0 + PositionVector.X_coordinate, -50.0 + PositionVector.Y_coordinate);
		glVertex2f(-50.0 + PositionVector.X_coordinate, -50.0 + PositionVector.Y_coordinate);
		glVertex2f(-50.0 + PositionVector.X_coordinate, 50.0 + PositionVector.Y_coordinate);
		glEnd();

	}
