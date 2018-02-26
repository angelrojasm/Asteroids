#include "Player.h"
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include "mathUtilities.h"
#include <cmath>


const float MaxSpeed = 350;
const float Friction = 0.999999f;

Player::Player()
{

	IsThrusting = false;
	Friction = 0;
	Radius = 10.0f;
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


/*Bullet Player::Shoot() {
	mathUtilities math;

	Bullet shot;

	if (HasCollided) {
		
		Vector2 Position;
		Position.X_coordinate =RenderingContainer[0].X_coordinate * sinf(math.degreestoradians(OrientationAngle));
		Position.Y_coordinate =RenderingContainer[0].Y_coordinate * cosf(math.degreestoradians(OrientationAngle));

		Vector2 BulletSpeed;


		BulletSpeed.X_coordinate = (Velocity.X_coordinate + 325) * sinf(math.degreestoradians(OrientationAngle));
		BulletSpeed.Y_coordinate = (Velocity.Y_coordinate + 325) * cosf(math.degreestoradians(OrientationAngle));

		shot.ChangePositions(PositionVector.X_coordinate,PositionVector.Y_coordinate);
		shot.ApplyImpulse(BulletSpeed);
	}
	else
	{
		shot.SetStatus(false);
	}
	return shot;

}

*/
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

	
			Entity::CreateEntityBounds();

	}

void::Player::Update(float deltaTime) {
	mathUtilities math;

	if (Velocity.Length() >= MaxSpeed) {
		setVelocity(Vector2((getVelocity().X_coordinate / Velocity.Length() * MaxSpeed), 
			(getVelocity().Y_coordinate / Velocity.Length() * MaxSpeed)));
	}

	if (!IsThrusting) {
		Velocity.X_coordinate *=0.99;
		Velocity.Y_coordinate *=0.99;
}

	Entity::Update(deltaTime);
}


