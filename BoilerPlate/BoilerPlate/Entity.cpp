#include "Entity.h"
#include "mathUtilities.h"

Entity::Entity()
{
	PositionVector = Vector2();
	mass = 0.5;
	OrientationAngle = 0;
	Acceleration = 0.166f;
	Velocity = 0;
	Debugging = false;
}


Entity::~Entity()
{
}


void::Entity::setDebugging(bool newValue) {
	Debugging = newValue;
	
}

bool::Entity::getDebugging() {
	return Debugging;
}

bool::Entity::HasCollided() {
	return Collision;
}

void::Entity::setOrientationAngle(float NewAngle) {
	OrientationAngle = NewAngle;
}

float::Entity::getOrientationAngle() {

	return OrientationAngle;
}

void::Entity::setVelocity(Vector2 newVelocity) {
	Velocity = newVelocity;
}

void::Entity::AccumulateVelocity(float AdditionValue) {
	Velocity.X_coordinate += AdditionValue;
	Velocity.Y_coordinate += AdditionValue;
}

Vector2 Entity::getVelocity() {
	return Velocity;
}

float::Entity::getRadius() {
	return Radius;
}

Vector2 Entity::getPositionVector() {
	return PositionVector;
}

float Entity::EntityDistance(Entity SecondEntity)
{
	float distance;
	float finalX = SecondEntity.PositionVector.X_coordinate - PositionVector.X_coordinate;
	float finalY = SecondEntity.PositionVector.Y_coordinate - PositionVector.Y_coordinate;

	distance = std::sqrt(finalX * finalX + finalY * finalY);

	return distance;
}

bool Entity::DetectCollision(Entity SecondEntity)
{
	float RadiusSum = Radius + SecondEntity.Radius;

	float entityDistance = EntityDistance(SecondEntity);

	bool DetectedCollision = entityDistance <= RadiusSum;

	if (DetectedCollision && !Debugging)
	{
		Collision = true;
	}

	return DetectedCollision;
}

float::Entity::warp(float AxisPosition, int MinBorder, int MaxBorder) {
	if (AxisPosition < MinBorder) {
		AxisPosition = MaxBorder - (MinBorder - AxisPosition);
		return AxisPosition;
	}

	if (AxisPosition > MaxBorder) {
		AxisPosition = MinBorder + (AxisPosition - MaxBorder);
		return AxisPosition;
	}
	return AxisPosition;
}
void::Entity::MoveForward() {
	mathUtilities math;

	Velocity.X_coordinate -= (10 / mass) * sinf(math.degreestoradians(OrientationAngle));
	Velocity.Y_coordinate += (10 / mass) * cosf(math.degreestoradians(OrientationAngle));

	PositionVector.X_coordinate = warp(PositionVector.X_coordinate, minWidthBorder, maxWidthBorder);
	PositionVector.Y_coordinate = warp(PositionVector.Y_coordinate, minHeightBorder, maxHeightBorder);
}

void::Entity::CreateEntityBounds(void)
{
	if (Debugging) {
		mathUtilities math;

		int lineAmount = 100;


		glLoadIdentity();

		glBegin(GL_LINE_LOOP);
		for (int i = 0; i <= lineAmount; i++)
		{
			glVertex2f(PositionVector.X_coordinate + (Radius * cos(i * (math.pi * 2) / lineAmount)),
				PositionVector.Y_coordinate + (Radius * sin(i * (math.pi * 2) / lineAmount)));
		}
		glEnd();
	}
}

void::Entity::ChangePositions(float newX, float newY) {
	PositionVector.X_coordinate = newX;
	PositionVector.Y_coordinate = newY;
}
void::Entity::Render() {

}

void::Entity::Update(float deltaTime) {

	
	PositionVector.X_coordinate += (Velocity.X_coordinate * deltaTime);
	PositionVector.Y_coordinate += (Velocity.Y_coordinate * deltaTime);

	PositionVector.X_coordinate = warp(PositionVector.X_coordinate, minWidthBorder, maxWidthBorder);
	PositionVector.Y_coordinate = warp(PositionVector.Y_coordinate, minHeightBorder, maxHeightBorder);
}