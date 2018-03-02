#include "ColorPalette.hpp"
using namespace std;

ColorPalette::ColorPalette()
{
}
Color ColorPalette::Red() {
	Color red = Color(1.0, 0, 0, 0);
	return red;
}
Color ColorPalette::Blue() {
	Color blue = Color(0, 0, 1, 0);
	return blue;
}
Color ColorPalette::Green() {
	Color green = Color(0, 1, 0, 0);
	return green;
}
Color ColorPalette::Gold() {
	Color dorado = Color(0.25, 0.25, 0, 0.25);
	return dorado;
}
Color ColorPalette::Purple() {
	Color morado = Color(0.5, 0, 0.5, 0);
	return morado;
}