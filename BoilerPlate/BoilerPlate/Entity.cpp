#include "Entity.h"



Entity::Entity()
{
	PositionVector = Vector2();
	mass = 0;
	OrientationAngle = 0;
}


Entity::~Entity()
{
}


void::Entity::setOrientationAngle(float NewAngle) {
	OrientationAngle = NewAngle;
}

float::Entity::getOrientationAngle() {

	return OrientationAngle;
}

float::Entity::warp(float AxisPosition, int MinBorder, int MaxBorder) {
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

void::Entity::Render() {

}