#include "Player.h"
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
const int minWidthBorder = -568;
const int maxWidthBorder = 568;
const int minHeightBorder = -320;
const int maxHeightBorder = 320;

Player::Player()
{
	PositionVector = Vector2();
	
}


Player::~Player()
{
}

float::Player::warp(float AxisPosition, int MinBorder, int MaxBorder) {
	if (AxisPosition < MinBorder) {
		AxisPosition = MaxBorder + (MinBorder - AxisPosition);
		return AxisPosition;
	}
	
	if (AxisPosition > MaxBorder) {
		AxisPosition = MinBorder - (AxisPosition - MaxBorder);
		return AxisPosition;
	}
	return AxisPosition;
}
void::Player::move(Vector2 UnitVector) {

	PositionVector.X_coordinate += UnitVector.X_coordinate;
	PositionVector.Y_coordinate += UnitVector.Y_coordinate;

	PositionVector.X_coordinate = warp(PositionVector.X_coordinate, minWidthBorder, maxWidthBorder);
	PositionVector.Y_coordinate = warp(PositionVector.Y_coordinate, minHeightBorder, maxHeightBorder);


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
