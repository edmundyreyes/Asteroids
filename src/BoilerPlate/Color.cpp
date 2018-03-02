#include "Color.hpp"
using namespace std;

Color::Color() {} 

Color::Color(float newRedValue, float newGreenValue, float newBlueValue, float newAlphValue) {
	redValue   = newRedValue;
	greenValue = newGreenValue;
	blueValue  = newBlueValue;
	alphValue  = newAlphValue;
}

