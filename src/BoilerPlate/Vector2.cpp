#include "Vector2.h"
#include <cmath>
using namespace std;

Vector2::Vector2(){
	x =		 0.0;
	y =		 0.0;
	length = 0.0;
}
Vector2::Vector2(float newx, float newy) {
	x		= newx;
	y		= newy;
	length = Length();
}
Vector2::Vector2(float parametro) {
	x = parametro;
	y = parametro;
	length = Length();
}
float Vector2::Length()  {
	return sqrt(x * x + y * y);
}
float Vector2::SquaredLength() {
	return x * x + y * y;
}
float Vector2::Normalize() { 
	Length();
	//se invierte el valor de lenght para asi multiplicar y 
	//acortar el work del cpu
	float inverseScale = 1.0 / length;
	x *= inverseScale;
	y *= inverseScale;

	return length;
}
Vector2& Vector2::operator=(const Vector2& rhs) {
	if (this == &rhs) return *this;
	x = rhs.x;
	y = rhs.y;
	return *this;
}
Vector2& Vector2::operator+=(const Vector2& rhs) {
	x += rhs.x;
	y += rhs.y;
	return *this;
}
Vector2& Vector2::operator-=(const Vector2& rhs) {
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}
Vector2& Vector2::operator*=(const Vector2& rhs) {
	x = x * rhs.x;
	y = y * rhs.y;
	return *this;
}
Vector2& Vector2::operator/=(const Vector2& rhs) {
	// si es 0; el divisor
	if (rhs.x == 0) throw " no se divide por 0";
	if (rhs.y == 0) throw " no se divide por 0";
	
	x = x / rhs.x;
	y = y / rhs.y;
	return *this;
}
Vector2 Vector2::operator+(const Vector2& rhs) {
	return Vector2(x + rhs.x, y + rhs.y );
}
Vector2 Vector2::operator-(const Vector2& rhs) {
	return Vector2(x - rhs.x, y - rhs.y);
}
Vector2 Vector2::operator*(const Vector2& rhs) {
	return Vector2(x * rhs.x, y * rhs.y);
}
Vector2 Vector2::operator/(const Vector2& rhs) {
	// si es 0; el divisor
	if (rhs.x == 0) throw " no se divide por 0";
	if (rhs.y == 0) throw " no se divide por 0";
	
	return Vector2(x / rhs.x, y / rhs.y);
}
bool Vector2::operator==(const Vector2& rhs) {
	return x == rhs.x && y == rhs.y;
}
bool Vector2::operator!=(const Vector2& rhs) {
	return x != rhs.x || y != rhs.y;
}
Vector2 operator*(float num, const Vector2& rhs) {
	return Vector2(num * rhs.x, num * rhs.y);
}
Vector2 operator*(const Vector2& lhs, float num) {
	return Vector2(num * lhs.x, num * lhs.y);
}
