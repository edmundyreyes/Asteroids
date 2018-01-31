#include <iostream>
class Color {
private:
	float redValue;
	float greenValue;
	float blueValue;
	float alphValue;
public:
	Color();
	//void ~color();
	Color(float redValue, float greenValue, float blueValue, float alphValue);
	void setRedValue(float value) {
		redValue = value;
	}
	float getRedValue() {
		return redValue;
	}
	void setGreenValue(float value) {
		greenValue = value;
	}
	float getGreenValue() {
		return greenValue;
	}
	void setBlueValue(float value) {
		blueValue = value;
	}
	float getBlueValue() {
		return blueValue;
	}
	void setAlphValue(float value) {
		alphValue = value;
	}
	float getAlphValue() {
		return alphValue;
	}
};
