#include "Vector4.h"
#include <cmath>



Vector4::Vector4()
{
	X_coordinate = 0.0f;
	Y_coordinate = 0.0f;
	Z_coordinate = 0.0f;
	w = 0.0f;
	length = 0.0f;
}

Vector4::Vector4(float Assignment)
{
	X_coordinate = Assignment;
	Y_coordinate = Assignment;
	Z_coordinate = Assignment;
	w = 0.0f;
	length = 0.0f;
}

Vector4::Vector4(float xValue, float yValue, float zValue, float wValue)
{
	X_coordinate = xValue;
	Y_coordinate = yValue;
	Z_coordinate = zValue;
	w = wValue;
	length = 0.0f;
}

Vector4::~Vector4()
{
}


float Vector4::Length()
{
	return sqrt((X_coordinate * X_coordinate) + (Y_coordinate * Y_coordinate) + (Z_coordinate * Z_coordinate) + (w * w));
}

float Vector4::SquaredLength() {
	return (X_coordinate * X_coordinate) + (Y_coordinate * Y_coordinate) + (Z_coordinate * Z_coordinate) + ( w * w );
}

float Vector4::Normalize() {
	X_coordinate /= length;
	Y_coordinate /= length;
	Z_coordinate /= length;
	w /= length;

	length = Length();

	return length;
}
// Operator Functions
Vector4& Vector4::operator=(const Vector4& SecondVector)
{
	if (this == &SecondVector)
	{
		return *this;
	}

	this->X_coordinate = SecondVector.X_coordinate;
	this->Y_coordinate = SecondVector.Y_coordinate;
	this->Z_coordinate = SecondVector.Z_coordinate;
	this->w = SecondVector.w;

	return *this;

}

Vector4& Vector4::operator+=(const Vector4& SecondVector)
{

	X_coordinate = X_coordinate + SecondVector.X_coordinate;
	Y_coordinate = Y_coordinate + SecondVector.Y_coordinate;
	Z_coordinate = Z_coordinate + SecondVector.Z_coordinate;
	w = w + SecondVector.w;


	return *this;
}

Vector4& Vector4::operator-=(const Vector4& SecondVector)
{
	X_coordinate = X_coordinate - SecondVector.X_coordinate;
	Y_coordinate = Y_coordinate - SecondVector.Y_coordinate;
	Z_coordinate = Z_coordinate - SecondVector.Z_coordinate;
	w = w - SecondVector.w;

	return *this;
}

Vector4& Vector4::operator*=(const Vector4& SecondVector)
{
	X_coordinate = X_coordinate * SecondVector.X_coordinate;
	Y_coordinate = Y_coordinate * SecondVector.Y_coordinate;
	Z_coordinate = Z_coordinate * SecondVector.Z_coordinate;
	w = w * SecondVector.w;



	return *this;
}

Vector4& Vector4::operator/=(const Vector4& SecondVector)
{
	X_coordinate = X_coordinate / SecondVector.X_coordinate;
	Y_coordinate = Y_coordinate / SecondVector.Y_coordinate;
	Z_coordinate = Z_coordinate / SecondVector.Z_coordinate;
	w = w / SecondVector.w;

	return *this;
}

Vector4 Vector4::operator+(const Vector4& SecondVector)
{
	Vector4 sum;

	sum.X_coordinate = X_coordinate + SecondVector.X_coordinate;
	sum.Y_coordinate = Y_coordinate + SecondVector.Y_coordinate;
	sum.Z_coordinate = Z_coordinate + SecondVector.Z_coordinate;
	sum.w = w + SecondVector.w;


	return sum;
}

Vector4 Vector4::operator-(const Vector4& SecondVector)
{
	Vector4 sub;
	sub.X_coordinate = X_coordinate - SecondVector.X_coordinate;
	sub.Y_coordinate = Y_coordinate - SecondVector.Y_coordinate;
	sub.Z_coordinate = Z_coordinate - SecondVector.Z_coordinate;
	sub.w = w - SecondVector.w;

	return sub;
}


Vector4 Vector4::operator*(const Vector4& SecondVector)
{
	Vector4 Scalar;

	Scalar.X_coordinate = X_coordinate * SecondVector.X_coordinate;
	Scalar.Y_coordinate = Y_coordinate * SecondVector.Y_coordinate;
	Scalar.Z_coordinate = Z_coordinate * SecondVector.Z_coordinate;
	Scalar.w = w * SecondVector.w;


	return Scalar;
}

Vector4 Vector4::operator/(const Vector4& SecondVector)
{
	Vector4 Division;

	Division.X_coordinate = X_coordinate / SecondVector.X_coordinate;
	Division.Y_coordinate = Y_coordinate / SecondVector.Y_coordinate;
	Division.Z_coordinate = Z_coordinate / SecondVector.Z_coordinate;
	Division.w = w / SecondVector.w;


	return Division;
}

bool Vector4::operator==(const Vector4& SecondVector)
{
	return
		X_coordinate == SecondVector.X_coordinate &&
		Y_coordinate == SecondVector.Y_coordinate;
		Z_coordinate == SecondVector.Z_coordinate;
		w == SecondVector.w;

}

bool Vector4::operator!=(const Vector4& SecondVector)
{
	return
		X_coordinate != SecondVector.X_coordinate ||
		Y_coordinate != SecondVector.Y_coordinate;
		Z_coordinate != SecondVector.Z_coordinate;
		w != SecondVector.w;

}

// friend functions
Vector4 operator*(float Scalar, const Vector4& SecondVector)
{
	Vector4 Final_Vector;
	Final_Vector.X_coordinate = Scalar * SecondVector.X_coordinate;
	Final_Vector.Y_coordinate = Scalar * SecondVector.Y_coordinate;
	Final_Vector.Z_coordinate = Scalar * SecondVector.Z_coordinate;
	Final_Vector.w = Scalar * SecondVector.w;


	return Final_Vector;
}

Vector4 operator*(const Vector4& FirstVector, float Scalar)
{
	Vector4 Final_Vector;
	Final_Vector.X_coordinate = Scalar * FirstVector.X_coordinate;
	Final_Vector.Y_coordinate = Scalar * FirstVector.Y_coordinate;
	Final_Vector.Z_coordinate = Scalar * FirstVector.Z_coordinate;
	Final_Vector.w = Scalar * FirstVector.w;


	return Final_Vector;
}
