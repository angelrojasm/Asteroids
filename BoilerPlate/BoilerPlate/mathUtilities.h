#pragma once
class mathUtilities
{
public:
	mathUtilities();
	~mathUtilities();
	

	const float pi = 3.1415926535897932384626433832795028841971693f;



	int FloatToInt(float x);
	int RoundtoEven(float x);
	float getmaximmumof2(float a, float b);
	float getmaximmumof3(float a, float b, float c);
	float getmaximmumof4(float a, float b, float c, float d);
	float Clamp(float x, int minboundary, int maxboundary);
	float degreestoradians(float angle);
	float radianstodegrees(float angle);
	float angulardistance(float A, float B);
	bool PowerofTwo(int number);
	int Interpolate(float percentage, int minrange, int maxrange);

};


	

