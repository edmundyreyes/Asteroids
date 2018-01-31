#include "ColorPalet.hpp"
using namespace std;

Color ColorPalet::red(){
	Color red = Color(1.0,0,0,0); 
	return red;
}
Color ColorPalet::blue() {
	Color blue = Color(0, 0, 1, 0);
	return blue;
}
Color ColorPalet::green() {
	Color green = Color(0, 1, 0, 0);
	return green;
}
Color ColorPalet::dorado() {
	Color dorado = Color(0.25, 0.25, 0, 0.25);
	return dorado;
}
Color ColorPalet::morado() {
	Color morado = Color(0.5, 0, 0.5, 0);
	return morado;
}
