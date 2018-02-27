#include "Asteroid.hpp"
#include "mathUtilities.h"


const float Asteroid_Moving_Speed = 30.0f;
const float Asteroid_Rotating_Speed = 30.0f;
const float Size_Inverse_Scale_Small = 0.3333f;
const float Size_Inverse_Scale_Medium = 0.5f;
const float Asteroid_Base_Size = 60.0f;

Asteroid::Asteroid()
{

	PositionVector = Vector2();
	OrientationAngle = 0;
	Size = Asteroid::AsteroidSize::size::SMALL;

	switch (Size) {
	case Asteroid::AsteroidSize::size::SMALL:
		mass = 1;
		Radius = Asteroid_Base_Size * Size_Inverse_Scale_Small;
		break;
	case Asteroid::AsteroidSize::size::MEDIUM:
		mass = 1.5;
		Radius = Asteroid_Base_Size * Size_Inverse_Scale_Medium;
		break;
	case Asteroid::AsteroidSize::size::BIG:
		mass = 3;
		Radius = Asteroid_Base_Size;
		break;
	}





	RenderingContainer.push_back(Vector2(0, -10));
	RenderingContainer.push_back(Vector2(-20, 20));
	RenderingContainer.push_back(Vector2(10, 50));
	RenderingContainer.push_back(Vector2(50, 50));
	RenderingContainer.push_back(Vector2(70, 20));
	RenderingContainer.push_back(Vector2(70, -10));
	RenderingContainer.push_back(Vector2(50, -30));
	RenderingContainer.push_back(Vector2(30, -30));
	RenderingContainer.push_back(Vector2(30, 0));
	RenderingContainer.push_back(Vector2(10, -30));
	RenderingContainer.push_back(Vector2(-20, 0));

}

Asteroid::Asteroid(Asteroid::AsteroidSize::size Asteroid_Size, float Orientation_Angle, float X_Position, float Y_Position) {

	PositionVector = Vector2();
	Size = Asteroid_Size;
	PositionVector.X_coordinate = X_Position;
	PositionVector.Y_coordinate = Y_Position;
	OrientationAngle = Orientation_Angle;
	ApplyImpulse(Vector2(Asteroid_Moving_Speed, Asteroid_Moving_Speed));

	switch (Size) {
	case Asteroid::AsteroidSize::size::SMALL:
		mass = 2;
		Radius = 40 * Size_Inverse_Scale_Small;
		break;
	case Asteroid::AsteroidSize::size::MEDIUM:
		mass = 4;
		Radius = 40 * Size_Inverse_Scale_Medium;
		break;
	case Asteroid::AsteroidSize::size::BIG:
		mass = 6;
		Radius = 40;
	}

	RenderingContainer.push_back(Vector2(0, -10));
	RenderingContainer.push_back(Vector2(-20, 20));
	RenderingContainer.push_back(Vector2(10, 50));
	RenderingContainer.push_back(Vector2(50, 50));
	RenderingContainer.push_back(Vector2(70, 20));
	RenderingContainer.push_back(Vector2(70, -10));
	RenderingContainer.push_back(Vector2(50, -30));
	RenderingContainer.push_back(Vector2(30, -30));
	RenderingContainer.push_back(Vector2(30, 0));
	RenderingContainer.push_back(Vector2(10, -30));
	RenderingContainer.push_back(Vector2(-20, 0));

}

Asteroid::~Asteroid()
{
}

Asteroid::AsteroidSize::size Asteroid::getSize() {

	return Size;

};

void::Asteroid::ApplyImpulse(Vector2 Impulse) {
	mathUtilities math;

	int ExtraImpulse = (Asteroid_Moving_Speed / ((int)Size + 1)) * 2;

	Velocity.X_coordinate -= (Impulse.X_coordinate / mass) * sinf(math.degreestoradians(OrientationAngle)) + ExtraImpulse;
	Velocity.Y_coordinate += (Impulse.Y_coordinate / mass) * cosf(math.degreestoradians(OrientationAngle)) + ExtraImpulse;

	PositionVector.X_coordinate = warp(PositionVector.X_coordinate, minWidthBorder, maxWidthBorder);
	PositionVector.Y_coordinate = warp(PositionVector.Y_coordinate, minHeightBorder, maxHeightBorder);
}



void::Asteroid::Update(float deltaTime) {

	OrientationAngle += Asteroid_Rotating_Speed * deltaTime;
	Entity::Update(deltaTime);
}

void::Asteroid::Render() {

	glLoadIdentity();
	glTranslatef(PositionVector.X_coordinate, PositionVector.Y_coordinate, 0.0f);
	glRotatef(OrientationAngle, 0, 0, 1);


	glBegin(GL_LINE_LOOP);

	switch (Size) {

	case Asteroid::AsteroidSize::size::SMALL:

		for (Vector2 Points : RenderingContainer) {
			glVertex2f(Points.X_coordinate * Size_Inverse_Scale_Small, Points.Y_coordinate * Size_Inverse_Scale_Small);
		}
		break;

	case Asteroid::AsteroidSize::size::MEDIUM:
		for (Vector2 Points : RenderingContainer) {
			glVertex2f(Points.X_coordinate * Size_Inverse_Scale_Medium, Points.Y_coordinate * Size_Inverse_Scale_Medium);
		}
		break;
	case Asteroid::AsteroidSize::size::BIG:
		for (Vector2 Points : RenderingContainer) {
			glVertex2f(Points.X_coordinate, Points.Y_coordinate);
		}
		break;
	default:
		break;

	}
	glEnd();

	CreateEntityBounds();
}