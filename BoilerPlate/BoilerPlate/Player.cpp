#include "Player.h"
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include "mathUtilities.h"
#include <cmath>

const int minWidthBorder = -568;
const int maxWidthBorder = 568;
const int minHeightBorder = -320;
const int maxHeightBorder = 320;


Player::Player()
{

	IsThrusting = false;
	RenderingContainer.push_back(Vector2(0, 20));
	RenderingContainer.push_back(Vector2(12, -10));
	RenderingContainer.push_back(Vector2(6, -4));
	RenderingContainer.push_back(Vector2(-6, -4));
	RenderingContainer.push_back(Vector2(-12, -10));

	ThrusterContainer.push_back(Vector2(6, -4));
	ThrusterContainer.push_back(Vector2(-6, -4));
	ThrusterContainer.push_back(Vector2(0, -14));


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


void::Player::Render()
	{
		glLoadIdentity();
		glTranslatef(PositionVector.X_coordinate, PositionVector.Y_coordinate, 0.0f);
		glRotatef(OrientationAngle, 0, 0, 1);
		

		glBegin(GL_LINE_LOOP);

		for (Vector2 Points : RenderingContainer) {
			glVertex2f(Points.X_coordinate,Points.Y_coordinate);
		}

		glEnd();
		if (IsThrusting) {
			glBegin(GL_LINE_LOOP);
			
			for (Vector2 Points :ThrusterContainer) {
				glVertex2f(Points.X_coordinate, Points.Y_coordinate);
			}
			glEnd();
		}



	}
