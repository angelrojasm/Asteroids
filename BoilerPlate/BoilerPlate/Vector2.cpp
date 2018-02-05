#include "Vector2.h"
#include <cmath>



Vector2::Vector2()
{
	X_coordinate= 0.0f;
	Y_coordinate = 0.0f;
	length = 0.0f;
}

Vector2::Vector2(float Assignment)
{
	X_coordinate = Assignment;
	Y_coordinate = Assignment;
	length = 0.0f;
}

Vector2::Vector2(float xValue, float yValue)
{
	X_coordinate = xValue;
	Y_coordinate = yValue;
	length = 0.0f;
}

Vector2::~Vector2()
{
}


float Vector2::Length()
{
	return sqrt(X_coordinate * X_coordinate + Y_coordinate * Y_coordinate);
}

float Vector2::SquaredLength() {
	return (X_coordinate * X_coordinate) + (Y_coordinate * Y_coordinate);
}

float Vector2::Normalize() {
	X_coordinate /= length;
	Y_coordinate /= length;

	length = Length();

	return length;
}
// Operator Functions
Vector2& Vector2::operator=(const Vector2& SecondVector)
{
	if (this == &SecondVector)
	{
		return *this;
	}

	this->X_coordinate = SecondVector.X_coordinate;
	this->Y_coordinate = SecondVector.Y_coordinate;

	return *this;
	
}

Vector2& Vector2::operator+=(const Vector2& SecondVector)
{
	
	X_coordinate = X_coordinate + SecondVector.X_coordinate;
	X_coordinate = X_coordinate + SecondVector.X_coordinate;

	return *this;
}

Vector2& Vector2::operator-=(const Vector2& SecondVector)
{
	X_coordinate = X_coordinate - SecondVector.X_coordinate;
	X_coordinate = X_coordinate - SecondVector.X_coordinate;

	return *this;
}

Vector2& Vector2::operator*=(const Vector2& SecondVector)
{
	X_coordinate = X_coordinate * SecondVector.X_coordinate;
	X_coordinate = X_coordinate * SecondVector.X_coordinate;

	return *this;
}

Vector2& Vector2::operator/=(const Vector2& SecondVector)
{
	X_coordinate = X_coordinate / SecondVector.X_coordinate;
	X_coordinate = X_coordinate / SecondVector.X_coordinate;

	return *this;
}

Vector2 Vector2::operator+(const Vector2& SecondVector)
{
	Vector2 sum;

	sum.X_coordinate = X_coordinate + SecondVector.X_coordinate;
	sum.X_coordinate = X_coordinate + SecondVector.X_coordinate;

	return sum;
}

Vector2 Vector2::operator-(const Vector2& SecondVector)
{
	Vector2 sub;
	sub.X_coordinate = X_coordinate - SecondVector.X_coordinate;
	sub.X_coordinate = X_coordinate - SecondVector.X_coordinate;

	return sub;
}


Vector2 Vector2::operator*(const Vector2& SecondVector)
{
	Vector2 Scalar;

	Scalar.X_coordinate = X_coordinate * SecondVector.X_coordinate;
	Scalar.X_coordinate = X_coordinate * SecondVector.X_coordinate;

	return Scalar;
}

Vector2 Vector2::operator/(const Vector2& SecondVector)
{
	Vector2 Division;

	Division.X_coordinate = X_coordinate / SecondVector.X_coordinate;
	Division.X_coordinate = X_coordinate / SecondVector.X_coordinate;

	return Division;
}

bool Vector2::operator==(const Vector2& SecondVector)
{
	return
		X_coordinate == SecondVector.X_coordinate &&
		X_coordinate == SecondVector.X_coordinate;
}

bool Vector2::operator!=(const Vector2& SecondVector)
{
	return
		X_coordinate != SecondVector.X_coordinate ||
		X_coordinate != SecondVector.X_coordinate;
}

// friend functions
Vector2 operator*(float Scalar, const Vector2& SecondVector)
{
	Vector2 Final_Vector;
	Final_Vector.X_coordinate = Scalar * SecondVector.X_coordinate;
	Final_Vector.X_coordinate = Scalar * SecondVector.X_coordinate;

	return Final_Vector;
}

Vector2 operator*(const Vector2& FirstVector, float Scalar)
{
	Vector2 Final_Vector;
	Final_Vector.X_coordinate = Scalar * FirstVector.X_coordinate;
	Final_Vector.X_coordinate = Scalar * FirstVector.X_coordinate;

	return Final_Vector;
}
