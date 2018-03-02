#include "MathUtilities.hpp"
#include "Math.h"
using namespace std;

MathUtilities::MathUtilities(){
}

float MathUtilities::PI = (float)(3.141592);

float MathUtilities::floatToInt(float x){
	float y = 0;
	y = round(x);
	return y;
}
float MathUtilities::floatToEven(float x) {
	float y = 0;
	y = round(x);
	if (y - 2 == 1) y += 1;
	return y;
}
float MathUtilities::clamp(float num, float min, float max) {
	return (num / min) * max;
}

float MathUtilities::degreesToRadians(float angle) {
	return (float)(angle * 0.01745);
}

float MathUtilities::radiansToDegrees(float radian) {
	float x =  (float)(radian * 57.295779513);
	x = round(x);
	return x;
}
float MathUtilities::radiansDistance(float radianA, float radianB) {
	radianB -= radianA;
	return radianB;
}
float MathUtilities::angularDistance(float angleA, float angleB) {
	angleB -= angleA;
	return angleB;
}

bool MathUtilities::isAPowerOfTwo(int num) {
	if (num % 2 == 1) return false;
	int n = num;
	for (int i = 0; i < n; i++) {
		if (num == 2) return true;
		num = num / 2;
		if (num % 2 == 1) {
			return false;
		}
	}
}
float MathUtilities::interpolate(float start, float end, float target) {
	float res = 0;
	res = target * (end - start) + start;
	return res;
}