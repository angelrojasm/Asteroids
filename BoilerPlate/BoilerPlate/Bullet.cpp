#include "Bullet.hpp"

const float MaxDistance = 45.0f;


Bullet::Bullet()
{
	TravelledDistance = 0;
	Radius = 3;
	IsActive = true;
	mass = 0.5f;

}

void::Bullet::ApplyImpulse(Vector2 Impulse) {




	Velocity.X_coordinate -= (Impulse.X_coordinate / mass);
	Velocity.Y_coordinate += (Impulse.Y_coordinate / mass);

}



void::Bullet::Update(float deltaTime)
{

	if (TravelledDistance < MaxDistance)
		TravelledDistance++;
	else
		IsActive = false;

	Entity::Update(deltaTime);
}

void::Bullet::Render(void)
{
	if (IsActive)
	{
		glLoadIdentity();
		glPointSize(5.0f);
		glBegin(GL_POINTS);
		glVertex2f(PositionVector.X_coordinate, PositionVector.Y_coordinate);
		glEnd();


		CreateEntityBounds();
		
	}
}



bool::Bullet::getStatus(void)
{
	return IsActive;
}

void::Bullet::SetStatus(bool newValue) {
	IsActive = newValue;
}