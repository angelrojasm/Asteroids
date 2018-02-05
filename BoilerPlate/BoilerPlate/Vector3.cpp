#include "Vector3.h"
#include <cmath>



Vector3::Vector3()
{
	X_coordinate = 0.0f;
	Y_coordinate = 0.0f;
	Z_coordinate = 0.0f;
	length = 0.0f;
}

Vector3::Vector3(float Assignment)
{
	X_coordinate = Assignment;
	Y_coordinate = Assignment;
	Z_coordinate = Assignment;
	length = 0.0f;
}

Vector3::Vector3(float xValue, float yValue, float zValue)
{
	X_coordinate = xValue;
	Y_coordinate = yValue;
	Z_coordinate = zValue;
	length = 0.0f;
}

Vector3::~Vector3()
{
}


float Vector3::Length()
{
	return sqrt((X_coordinate * X_coordinate) + (Y_coordinate * Y_coordinate));
}

float Vector3::SquaredLength() {
	return (X_coordinate * X_coordinate) + (Y_coordinate * Y_coordinate) + (Z_coordinate * Z_coordinate);
}

float Vector3::Normalize() {
	X_coordinate /= length;
	Y_coordinate /= length;
	Z_coordinate /= length;

	length = Length();

	return length;
}
// Operator Functions
Vector3& Vector3::operator=(const Vector3& SecondVector)
{
	if (this == &SecondVector)
	{
		return *this;
	}

	this->X_coordinate = SecondVector.X_coordinate;
	this->Y_coordinate = SecondVector.Y_coordinate;
	this->Z_coordinate = SecondVector.Z_coordinate;

	return *this;

}

Vector3& Vector3::operator+=(const Vector3& SecondVector)
{

	X_coordinate = X_coordinate + SecondVector.X_coordinate;
	Y_coordinate = Y_coordinate + SecondVector.Y_coordinate;
	Z_coordinate = Z_coordinate + SecondVector.Z_coordinate;

	return *this;
}

Vector3& Vector3::operator-=(const Vector3& SecondVector)
{
	X_coordinate = X_coordinate - SecondVector.X_coordinate;
	Y_coordinate = Y_coordinate - SecondVector.Y_coordinate;
	Z_coordinate = Z_coordinate - SecondVector.Z_coordinate;

	return *this;
}

Vector3& Vector3::operator*=(const Vector3& SecondVector)
{
	X_coordinate = X_coordinate * SecondVector.X_coordinate;
	Y_coordinate = Y_coordinate * SecondVector.Y_coordinate;
	Z_coordinate = Z_coordinate * SecondVector.Z_coordinate;


	return *this;
}

Vector3& Vector3::operator/=(const Vector3& SecondVector)
{
	X_coordinate = X_coordinate / SecondVector.X_coordinate;
	Y_coordinate = Y_coordinate / SecondVector.Y_coordinate;
	Z_coordinate = Z_coordinate / SecondVector.Z_coordinate;

	return *this;
}

Vector3 Vector3::operator+(const Vector3& SecondVector)
{
	Vector3 sum;

	sum.X_coordinate = X_coordinate + SecondVector.X_coordinate;
	sum.Y_coordinate = Y_coordinate + SecondVector.Y_coordinate;
	sum.Z_coordinate = Z_coordinate + SecondVector.Z_coordinate;


	return sum;
}

Vector3 Vector3::operator-(const Vector3& SecondVector)
{
	Vector3 sub;
	sub.X_coordinate = X_coordinate - SecondVector.X_coordinate;
	sub.Y_coordinate = Y_coordinate - SecondVector.Y_coordinate;
	sub.Z_coordinate = Z_coordinate - SecondVector.Z_coordinate;

	return sub;
}


Vector3 Vector3::operator*(const Vector3& SecondVector)
{
	Vector3 Scalar;

	Scalar.X_coordinate = X_coordinate * SecondVector.X_coordinate;
	Scalar.Y_coordinate = Y_coordinate * SecondVector.Y_coordinate;
	Scalar.Z_coordinate = Z_coordinate * SecondVector.Z_coordinate;


	return Scalar;
}

Vector3 Vector3::operator/(const Vector3& SecondVector)
{
	Vector3 Division;

	Division.X_coordinate = X_coordinate / SecondVector.X_coordinate;
	Division.Y_coordinate = Y_coordinate / SecondVector.Y_coordinate;
	Division.Z_coordinate = Z_coordinate / SecondVector.Z_coordinate;

	return Division;
}

bool Vector3::operator==(const Vector3& SecondVector)
{
	return
		X_coordinate == SecondVector.X_coordinate &&
		Y_coordinate == SecondVector.Y_coordinate;
		Z_coordinate == SecondVector.Z_coordinate;

}

bool Vector3::operator!=(const Vector3& SecondVector)
{
	return
		X_coordinate != SecondVector.X_coordinate ||
		Y_coordinate != SecondVector.Y_coordinate;
		Z_coordinate != SecondVector.Z_coordinate;

}

// friend functions
Vector3 operator*(float Scalar, const Vector3& SecondVector)
{
	Vector3 Final_Vector;
	Final_Vector.X_coordinate = Scalar * SecondVector.X_coordinate;
	Final_Vector.Y_coordinate = Scalar * SecondVector.Y_coordinate;
	Final_Vector.Z_coordinate = Scalar * SecondVector.Z_coordinate;


	return Final_Vector;
}

Vector3 operator*(const Vector3& FirstVector, float Scalar)
{
	Vector3 Final_Vector;
	Final_Vector.X_coordinate = Scalar * FirstVector.X_coordinate;
	Final_Vector.Y_coordinate = Scalar * FirstVector.Y_coordinate;
	Final_Vector.Z_coordinate = Scalar * FirstVector.Z_coordinate;


	return Final_Vector;
}
