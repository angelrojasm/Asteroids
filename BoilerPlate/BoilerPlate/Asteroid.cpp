#include "Asteroid.hpp"
#include "mathUtilities.h"


Asteroid::Asteroid()
{

	PositionVector = Vector2();
	OrientationAngle = 0;
	Size = Asteroid::AsteroidSize::size::SMALL;

	switch (Size) {
	case Asteroid::AsteroidSize::size::SMALL:
		mass = 2;
		Radius = Asteroid_Base_Size * Size_Inverse_Scale_Small;
		break;
	case Asteroid::AsteroidSize::size::MEDIUM:
		mass = 4;
		Radius = Asteroid_Base_Size * Size_Inverse_Scale_Medium;
		break;
	case Asteroid::AsteroidSize::size::BIG:
		mass = 6;
		Radius = Asteroid_Base_Size;
		break;
	}





	RenderingContainer.push_back(Vector2(-4, 30));
	RenderingContainer.push_back(Vector2(4, 28));
	RenderingContainer.push_back(Vector2(10, 24));
	RenderingContainer.push_back(Vector2(14, 18));
	RenderingContainer.push_back(Vector2(19, 12));

	RenderingContainer.push_back(Vector2(26, 8));
	RenderingContainer.push_back(Vector2(30, 0));
	RenderingContainer.push_back(Vector2(27, -8));
	RenderingContainer.push_back(Vector2(24, -18));
	RenderingContainer.push_back(Vector2(16, -24));

	RenderingContainer.push_back(Vector2(6, -28));
	RenderingContainer.push_back(Vector2(0, -30));
	RenderingContainer.push_back(Vector2(-10, -28));
	RenderingContainer.push_back(Vector2(-16, -26));
	RenderingContainer.push_back(Vector2(-20, -18));

	RenderingContainer.push_back(Vector2(-26, -8));
	RenderingContainer.push_back(Vector2(-30, 2));
	RenderingContainer.push_back(Vector2(-26, 13));
	RenderingContainer.push_back(Vector2(-20, 20));
	RenderingContainer.push_back(Vector2(-12, 27));

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
		Radius = 30 * Size_Inverse_Scale_Small;
		break;
	case Asteroid::AsteroidSize::size::MEDIUM:
		mass = 4;
		Radius = 30 * Size_Inverse_Scale_Medium;
		break;
	case Asteroid::AsteroidSize::size::BIG:
		mass = 6;
		Radius = 30;
	}



	RenderingContainer.push_back(Vector2(-4, 30));
	RenderingContainer.push_back(Vector2(4, 28));
	RenderingContainer.push_back(Vector2(10, 24));
	RenderingContainer.push_back(Vector2(14, 18));
	RenderingContainer.push_back(Vector2(19, 12));

	RenderingContainer.push_back(Vector2(26, 8));
	RenderingContainer.push_back(Vector2(30, 0));
	RenderingContainer.push_back(Vector2(27, -8));
	RenderingContainer.push_back(Vector2(24, -18));
	RenderingContainer.push_back(Vector2(16, -24));

	RenderingContainer.push_back(Vector2(6, -28));
	RenderingContainer.push_back(Vector2(0, -30));
	RenderingContainer.push_back(Vector2(-10, -28));
	RenderingContainer.push_back(Vector2(-16, -26));
	RenderingContainer.push_back(Vector2(-20, -18));

	RenderingContainer.push_back(Vector2(-26, -8));
	RenderingContainer.push_back(Vector2(-30, 2));
	RenderingContainer.push_back(Vector2(-26, 13));
	RenderingContainer.push_back(Vector2(-20, 20));
	RenderingContainer.push_back(Vector2(-12, 27));
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
	if (!Collision) {
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
}