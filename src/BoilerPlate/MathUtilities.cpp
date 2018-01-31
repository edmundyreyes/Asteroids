#include "MathUtilities.hpp"
#include "Math.h"
using namespace std;

MathUtilities::MathUtilities()
{
}
MathUtilities::~MathUtilities()
{}
int MathUtilities::floatToInt(float x){
	int y = 0;
	y = round(x);
	return y;
}
int MathUtilities::floatToEven(float x) {
	int y = 0;
	y = round(x);
	if (y % 2 == 1) y += 1;
	return y;
}
float MathUtilities::clamp(float num, int min, int max) {
	if (num < min) num = min;
	else if (num > max) num = max;
	return num;
}

float MathUtilities::degreesToRadians(int angle) {
	return angle * 0.01745329252;
}

int MathUtilities::radiansToDegrees(float radian) {
	float x =  radian * 57.295779513;
	x = round(x);
	return x;
}
int MathUtilities::radiansDistance(float radianA, float radianB) {
	radianB -= radianA;
	return radianB;
}
int MathUtilities::angularDistance(int angleA, int angleB) {
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