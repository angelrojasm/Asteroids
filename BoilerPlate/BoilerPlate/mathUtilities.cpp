#include "mathUtilities.h"
#include <cmath>
const float pi = 3.1415926535897932384626433832795028841971693;


mathUtilities::mathUtilities()
{
}


mathUtilities::~mathUtilities()
{
}






int mathUtilities::FloatToInt(float x) {

	float z = x;

	int y = (int)x;

	z -= y;

	if (z >= 0.5) {
		return ceil(x);

	}
	else
		if (z < 0.5) {
			return floor(x);
		}
}

int mathUtilities::RoundtoEven(float x) {

	float z = x;

	int y = (int)x;

	z -= y;

	if (z >= 0.5) {
		y = ceil(x);
		if (y % 2 == 0)
			return ceil(x);
		else
			return y + 1;

	}
	else
		if (z < 0.5) {
			y = floor(x);
			if (y % 2 == 0)
				return floor(x);
			else
				return y - 1;

		}
}

float mathUtilities::getmaximmumof2(float a, float b) {


	if (a > b)
		return a;
	else
		return b;

}


float mathUtilities::getmaximmumof3(float a, float b, float c) {

	float mayor = a;

	if (b > mayor)
		mayor = b;

	if (c > mayor)
		mayor = c;

	return mayor;
}

float mathUtilities::getmaximmumof4(float a, float b, float c, float d) {

	float mayor = a;

	if (b > mayor)
		mayor = b;

	if (c > mayor)
		mayor = c;

	if (d > mayor)
		mayor = d;

	return mayor;

}

float mathUtilities::Clamp(float x, int minboundary, int maxboundary) {



	if (x >= minboundary && x <= maxboundary)
		return x;
	else
		return minboundary;

}

float mathUtilities::degreestoradians(float angle) {


	return (angle * pi) / 180;

}

float mathUtilities::radianstodegrees(float angle) {


	return (angle * 180) / pi;


}

float mathUtilities::angulardistance(float A, float B) {

	return std::abs(A - B);


}


bool mathUtilities::PowerofTwo(int number) {


	return (ceil(log2(number)) == floor(log2(number)));

}


int mathUtilities::Interpolate(float percentage, int minrange, int maxrange) {


	if (percentage > 1 || percentage < 0)
		return 0;
	else


		return ((maxrange - minrange) * percentage) + minrange;

}




