#pragma once
class Vector2
{

public:
	//Members

	float X_coordinate;
	float Y_coordinate;
	float length;
	

	//Constructors

	Vector2();
	~Vector2();
	Vector2(float);
	Vector2(float, float);


//Function Headers
	
	float Length();
	float SquaredLength();
	float Normalize();

	//Overloads
	
	Vector2& operator+=(const Vector2& Second_Vector);
	Vector2& operator-=(const Vector2& Second_Vector);
	Vector2& operator*=(const Vector2& Second_Vector);
	Vector2& operator/=(const Vector2& Second_Vector);
	Vector2& operator= (const Vector2& Second_Vector);

	Vector2 operator+(const Vector2& Second_Vector);
	Vector2 operator-(const Vector2& Second_Vector);
	Vector2 operator*(const Vector2& Second_Vector);
	Vector2 operator/(const Vector2& Second_Vector);

	friend Vector2 operator*(float Scalar, const Vector2& SecondVector);
	friend Vector2 operator*(const Vector2& FirstVector, float Scalar);


	bool operator==(const Vector2& Comparison);
	bool operator!=(const Vector2& Comparison);
};

