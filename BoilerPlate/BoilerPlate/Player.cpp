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


void::Player::move(Vector2 UnitVector) {

	PositionVector.X_coordinate += UnitVector.X_coordinate;
	PositionVector.Y_coordinate += UnitVector.Y_coordinate;
}

void::Player::Update(SDL_KeyboardEvent keyBoardEvent)
{

	switch (keyBoardEvent.keysym.scancode) {

	case SDL_SCANCODE_W:
		move(Vector2(0, 10));
		if (PositionVector.Y_coordinate >= 310) {
			PositionVector.Y_coordinate = -310;
		}
		break;

	case SDL_SCANCODE_A:
		move(Vector2(-10, 0));
		if (PositionVector.X_coordinate <= -570) {
			PositionVector.X_coordinate = 560;
		}
		break;

	case SDL_SCANCODE_S:
		move(Vector2(0, -10));
		if (PositionVector.Y_coordinate <= -320) {
			PositionVector.Y_coordinate = 300;
		}
		break;

	case SDL_SCANCODE_D:
		
		move(Vector2(10, 0));
		if (PositionVector.X_coordinate >= 570) {
			PositionVector.X_coordinate = -560;
		}
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
		glVertex2f(0, 20);
		glVertex2f( 12, -10);
		glVertex2f(6, -4 );
		glVertex2f(-6, -4);
		glVertex2f(-12, -10);

		glEnd();


	}
