#include "Bullet.h"

const float MaxDistance = 100.0f;

Bullet::Bullet()
{
	TravelledDistance = 0;
	Radius = 4;
	IsActive = true;
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
		glPointSize(3.0f);
		glBegin(GL_POINTS);
		glVertex2f(PositionVector.X_coordinate,PositionVector.Y_coordinate);
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