#include "Color.hpp"
using namespace std;

Color::Color() {}
//void Color::~Color(){}
Color::Color(float newRedValue, float newGreenValue, float newBlueValue, float newAlphValue) {
	setRedValue(newRedValue);
	setGreenValue(newGreenValue);
	setBlueValue(newBlueValue);
	setAlphValue(newAlphValue);
}

