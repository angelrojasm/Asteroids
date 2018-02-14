#include "Player.h"
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include "mathUtilities.h"
const int minWidthBorder = -568;
const int maxWidthBorder = 568;
const int minHeightBorder = -320;
const int maxHeightBorder = 320;


Player::Player()
{
	PositionVector = Vector2();
	IsThrusting = false;
	OrientationAngle = 0;
	
}


Player::~Player()
{
}

bool::Player::getIsThrusting() {

	return IsThrusting;
}

void::Player::setIsThrusting(bool NewValue) {
	IsThrusting = NewValue;

}

void::Player::setOrientationAngle(float NewAngle) {
	OrientationAngle = NewAngle;
}

float::Player::getOrientationAngle() {

	return OrientationAngle;
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

void::Player::RotateLeft() {
	OrientationAngle += 10;
}

void::Player::RotateRight() {
	OrientationAngle -= 10;
}

void::Player::MoveForward() {
	mathUtilities math;

	PositionVector.X_coordinate -= (10 * sinf(math.degreestoradians(OrientationAngle)));
	PositionVector.Y_coordinate += (10 * cosf(math.degreestoradians(OrientationAngle)));

	PositionVector.X_coordinate = warp(PositionVector.X_coordinate, minWidthBorder, maxWidthBorder);
	PositionVector.Y_coordinate = warp(PositionVector.Y_coordinate, minHeightBorder, maxHeightBorder);
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
		glRotatef(OrientationAngle, 0, 0, 1);
		

		glBegin(GL_LINE_LOOP);
		glVertex2f(0, 20);
		glVertex2f( 12, -10);
		glVertex2f(6, -4 );
		glVertex2f(-6, -4);
		glVertex2f(-12, -10);

		glEnd();
		if (IsThrusting) {
			glBegin(GL_LINE_LOOP);
			glVertex2f(6, -4);
			glVertex2f(-6, -4);
			glVertex2f(0, -14);
			glEnd();
		}



	}
