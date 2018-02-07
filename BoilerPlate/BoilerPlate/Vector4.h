#pragma once
class Vector4
{

public:
	//Members

	float X_coordinate;
	float Y_coordinate;
	float Z_coordinate;
	float w;
	float length;


	//Constructors

	Vector4();
	~Vector4();
	Vector4(float);
	Vector4(float, float, float, float);


	//Function Headers

	float Length();
	float SquaredLength();
	float Normalize();

	//Overloads

	Vector4& operator+=(const Vector4& Second_Vector);
	Vector4& operator-=(const Vector4& Second_Vector);
	Vector4& operator*=(const Vector4& Second_Vector);
	Vector4& operator/=(const Vector4& Second_Vector);
	Vector4& operator= (const Vector4& Second_Vector);

	Vector4 operator+(const Vector4& Second_Vector);
	Vector4 operator-(const Vector4& Second_Vector);
	Vector4 operator*(const Vector4& Second_Vector);
	Vector4 operator/(const Vector4& Second_Vector);

	friend Vector4 operator*(float Scalar, const Vector4& SecondVector);
	friend Vector4 operator*(const Vector4& FirstVector, float Scalar);


	bool operator==(const Vector4& Comparison);
	bool operator!=(const Vector4& Comparison);
};

