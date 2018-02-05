#pragma once
class Vector3
{

public:
	//Members

	float X_coordinate;
	float Y_coordinate;
	float Z_coordinate;
	float length;


	//Constructors

	Vector3();
	~Vector3();
	Vector3(float);
	Vector3(float, float,float);


	//Function Headers

	float Length();
	float SquaredLength();
	float Normalize();

	//Overloads

	Vector3& operator+=(const Vector3& Second_Vector);
	Vector3& operator-=(const Vector3& Second_Vector);
	Vector3& operator*=(const Vector3& Second_Vector);
	Vector3& operator/=(const Vector3& Second_Vector);
	Vector3& operator= (const Vector3& Second_Vector);

	Vector3 operator+(const Vector3& Second_Vector);
	Vector3 operator-(const Vector3& Second_Vector);
	Vector3 operator*(const Vector3& Second_Vector);
	Vector3 operator/(const Vector3& Second_Vector);

	friend Vector3 operator*(float Scalar, const Vector3& SecondVector);
	friend Vector3 operator*(const Vector3& FirstVector, float Scalar);


	bool operator==(const Vector3& Comparison);
	bool operator!=(const Vector3& Comparison);
};

