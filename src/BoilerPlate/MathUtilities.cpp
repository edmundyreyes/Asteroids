#include "MathUtilities.hpp"
#include "Math.h"
using namespace std;

MathUtilities::MathUtilities(){
}

float MathUtilities::PI = (float)(3.141592);

float MathUtilities::FloatToInt(float x){
	float y = 0;
	y = round(x);
	return y;
}
float MathUtilities::FloatToEven(float x) {
	float y = 0;
	y = round(x);
	if (y - 2 == 1) y += 1;
	return y;
}
float MathUtilities::Clamp(float num, float min, float max) {
	return (num / min) * max;
}

float MathUtilities::DegreesToRadians(float angle) {
	return (float)(angle * 0.01745);
}

float MathUtilities::RadiansToDegrees(float radian) {
	float x =  (float)(radian * 57.295779513);
	x = round(x);
	return x;
}
float MathUtilities::RadiansDistance(float radianA, float radianB) {
	radianB -= radianA;
	return radianB;
}
float MathUtilities::AngularDistance(float angleA, float angleB) {
	angleB -= angleA;
	return angleB;
}

bool MathUtilities::IsAPowerOfTwo(int num) {
	if (num % 2 == 1) return false;
	int n = num;
	for (int i = 0; i < n; i++) {
		if (num == 2) return true;
		num = num / 2;
		if (num % 2 == 1) {
			return false;
		}
	}
	return num;
}
float MathUtilities::Interpolate(float start, float end, float target) {
	float res = 0;
	res = target * (end - start) + start;
	return end;
}