#include <iostream>
#include <String.h>
using namespace std;
class MathUtilities
{
public:
	MathUtilities();
	~MathUtilities();
	int floatToInt(float num);
	int floatToEven(float num);

	float clamp(float num, int min, int max);

	float degreesToRadians(int angle);
	int radiansToDegrees(float radian);

	int radiansDistance(float radianA, float radianB); // me falta esto
	int angularDistance(int angleA, int angleB);
	
	bool isAPowerOfTwo(int num);
	float interpolate(float start, float end, float target);

	template <class data>
	data getMin(data num1, data num2) {
		if (num1 <= num2) return num1
		else return num2;
	}
	template <class data>
	data getMin(data num1, data num2, data num3) {
		if (num1 <= num2) {
			if (num1 <= num3) return num1;
			else return num3;
		}
		else {
			if (num2 <= num3) return num2;
			else return num3;
		}
	}
	template <class data>
	data getMin(data num1, data num2, data num3, data num4) {
		if (num1 <= num2) {
			if (num3 <= num4) {
				if (num1 <= num3) return num1;
				else return num3;
			}
			else {
				if (num1 <= num4) return num1;
				else return num4;
			}
		}
		else {
			if (num3 <= num4) {
				if (num2 <= num3) return num2;
				else return num3;
			}
			else {
				if (num2 <= num4) return num2;
				else return num4;
			}
		}
	}
	template <class data>
	data getMax(data num1, data num2) {
		if (num1 >= num2) return num1
		else return num2;
	}
	template <class data>
	data getMax(data num1, data num2, data num3) {
		if (num1 >= num2) {
			if (num1 >= num3) return num1;
			else return num3;
		}
		else {
			if (num2 >= num3) return num2;
			else return num3;
		}
	}
	template <class data>
	data getMax(data num1, data num2, data num3, data num4) {
		if (num1 >= num2) {
			if (num3 >= num4) {
				if (num1 >= num3) return num1;
				else return num3;
			}
			else {
				if (num1 >= num4) return num1;
				else return num4;
			}
		}
		else {
			if (num3 >= num4) {
				if (num2 >= num3) return num2;
				else return num3;
			}
			else {
				if (num2 >= num4) return num2;
				else return num4;
			}
		}
	}
};

