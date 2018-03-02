#include "Player.h"
#include <GL/glew.h>
#include <SDL_opengl.h>
#include "mathUtilities.h"


const float MaxSpeed = 350;
const float Friction = 0.97f;
const float RotationUnits = 3.5f;
const float X_Position = -400.0f;
const float Y_Position = 300.0f;

Player::Player()
{
	PositionVector = Vector2(0.0f,0.0f);
	IsThrusting = false;
	Radius = 16;
	PlayerLives = 3;
	RenderingContainer.push_back(Vector2(0, 20));
	RenderingContainer.push_back(Vector2(12, -10));
	RenderingContainer.push_back(Vector2(6, -4));
	RenderingContainer.push_back(Vector2(-6, -4));
	RenderingContainer.push_back(Vector2(-12, -10));

	ThrusterContainer.push_back(Vector2(6, -4));
	ThrusterContainer.push_back(Vector2(-6, -4));
	ThrusterContainer.push_back(Vector2(0, -14));
	CanBeDestroyed = true;
	GameOver = false;
	
	
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
	OrientationAngle += RotationUnits;
}

void::Player::RotateRight() {
	OrientationAngle -= RotationUnits;
}


void::Player::MoveForward() {
	mathUtilities math;

	Velocity.X_coordinate -= (10 / mass) * sinf(math.degreestoradians(OrientationAngle));
	Velocity.Y_coordinate += (10 / mass) * cosf(math.degreestoradians(OrientationAngle));

	PositionVector.X_coordinate = warp(PositionVector.X_coordinate, minWidthBorder, maxWidthBorder);
	PositionVector.Y_coordinate = warp(PositionVector.Y_coordinate, minHeightBorder, maxHeightBorder);
}

Bullet* Player::Shoot() {
mathUtilities math;

Bullet* shot = new Bullet();

	if (PlayerLives > 0) {

Vector2 Position;
Position.X_coordinate =RenderingContainer[0].X_coordinate * sinf(math.degreestoradians(OrientationAngle));
Position.Y_coordinate =RenderingContainer[0].Y_coordinate * cosf(math.degreestoradians(OrientationAngle));

Vector2 BulletSpeed;


BulletSpeed.X_coordinate += (325) * sinf(math.degreestoradians(OrientationAngle));
BulletSpeed.Y_coordinate += (325) * cosf(math.degreestoradians(OrientationAngle));

shot->ChangePositions(PositionVector.X_coordinate,PositionVector.Y_coordinate);
shot->ApplyImpulse(BulletSpeed);

}
else
{
shot->SetStatus(false);
}
return shot;

}

int::Player::getPlayerLives() {
	return PlayerLives;
}

void::Player::AddLives(int Amount) {
	PlayerLives += Amount;
}

void::Player::LoseLives(int Amount) {
	PlayerLives -= Amount;
}

void::Player::setRespawning(bool newValue) {
	CanBeDestroyed = newValue;
}

bool::Player::getRespawningStatus() {
	return CanBeDestroyed;
}

void::Player::setGameOver(bool newValue) {
	GameOver = newValue;
}

bool::Player::getGameOverStatus() {
	return GameOver;
}

void::Player::MoveTo(Vector2 Coordinates) {
	PositionVector.X_coordinate = Coordinates.X_coordinate;
	PositionVector.Y_coordinate = Coordinates.Y_coordinate;
}
	void::Player::Render()
	{
		if (!GameOver) {
			glLoadIdentity();
			glTranslatef(PositionVector.X_coordinate, PositionVector.Y_coordinate, 0.0f);
			glRotatef(OrientationAngle, 0, 0, 1);


			glBegin(GL_LINE_LOOP);

			for (Vector2 Points : RenderingContainer) {
				glVertex2f(Points.X_coordinate, Points.Y_coordinate);
			}

			glEnd();
			if (IsThrusting) {
				glBegin(GL_LINE_LOOP);

				for (Vector2 Points : ThrusterContainer) {
					glVertex2f(Points.X_coordinate, Points.Y_coordinate);
				}
				glEnd();
			}



			float ResizeFactor = 0.7f;
			float IdealWidth = (float)maxWidthBorder / 1.5f;
			float IdealHeight = (float)maxHeightBorder / 1.1f;
			glLoadIdentity();
			glTranslatef(IdealWidth, IdealHeight, 0.0f);
			glColor3f(1.0f, 1.0f, 1.0f);
			for (int i = 0; i <PlayerLives; i++)
			{
				glBegin(GL_LINE_LOOP);
				for (int j = 0; j < RenderingContainer.size(); j++)
				{
					glVertex2f(ResizeFactor * RenderingContainer[j].X_coordinate + 30 * (i + 1),
						ResizeFactor * RenderingContainer[j].Y_coordinate - 20);
				}
				glEnd();
			}


			CreateEntityBounds();

		}
	}

	void::Player::Update(float deltaTime) {
		mathUtilities math;

		if (Velocity.Length() >= MaxSpeed) {
			setVelocity(Vector2((getVelocity().X_coordinate / Velocity.Length() * MaxSpeed),
				(getVelocity().Y_coordinate / Velocity.Length() * MaxSpeed)));
		}

		if (!IsThrusting) {
			Velocity.X_coordinate *= Friction;
			Velocity.Y_coordinate *= Friction;
		}

		Entity::Update(deltaTime);
	}