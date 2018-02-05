#include "Vector3.h"
#include<cmath>
#include "Vector2.h"


Vector3 Vector3::Origin = Vector3();

Vector3::Vector3(){
	x =		 0.0;
	y =		 0.0;
	z =		 0.0;
	length = 0.0;
}
Vector3::Vector3(float newx , float newy , float newz){
	x = newx;
	y = newy;
	z = newz;
	length = 0.0;
	Length();
}
Vector3::Vector3(float uni) {
	x = uni;
	y = uni;
	z = uni;
	length = 0.0;
	Length();
}
Vector3::Vector3(const Vector2& vec2) {
	x = vec2.x;
	y = vec2.y;
	z = 0.0;
	length = 0.0;
	Length();
}
float Vector3::Length(){
	return std::sqrt(x * x + y * y + z * z);
}
float Vector3::SquaredLength(){
	return x * x + y * y + z * z;
}
float Vector3::Normalize() {
	Length();
	//se invierte el valor de lenght para asi multiplicar y 
	//acortar el work del cpu
	float inverseScale = 1.0 / length;
	x *= inverseScale;
	y *= inverseScale;
	z *= inverseScale;
	return length;
}
Vector3& Vector3::operator=(const Vector3& rhs) {
	if (this == &rhs) return *this;
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	return *this;
}
Vector3& Vector3::operator+=(const Vector3& rhs) {
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}
Vector3& Vector3::operator-=(const Vector3& rhs) {
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}
Vector3& Vector3::operator*=(const Vector3& rhs) {
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	return *this;
}
Vector3& Vector3::operator/=(const Vector3& rhs) {
	// si es 0; el divisor
	if (rhs.x == 0) throw " no se divide por 0";
	if (rhs.y == 0) throw " no se divide por 0";
	if (rhs.z == 0) throw " no se divide por 0";

	x = x / rhs.x;
	y = y / rhs.y;
	z = z / rhs.z;
	return *this;
}
Vector3 Vector3::operator+ (const Vector3& rhs) {
	return Vector3(x + rhs.x, y + rhs.y, z + rhs.z );
}
Vector3 Vector3::operator- (const Vector3& rhs) {
	return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
}
Vector3 Vector3::operator* (const Vector3& rhs) {
	return Vector3(x * rhs.x, y * rhs.y, z * rhs.z);
}
Vector3 Vector3::operator/ (const Vector3& rhs) {
	if (rhs.x == 0) throw " no se divide por 0";
	if (rhs.y == 0) throw " no se divide por 0";
	if (rhs.z == 0) throw " no se divide por 0";

	return Vector3(x / rhs.x, y / rhs.y, z / rhs.z);
}
bool Vector3::operator==(const Vector3& rhs) {
	return x == rhs.x && y == rhs.y && z == rhs.z;
}
bool Vector3::operator!=(const Vector3& rhs) {
	return x == rhs.x || y == rhs.y || z == rhs.z;
}
Vector3 operator*(float unit, const Vector3& rhs) {
	return Vector3(unit * rhs.x, unit * rhs.y, unit * rhs.z);
}
Vector3 operator*(const Vector3& lhs, float unit) {
	return Vector3(unit * lhs.x, unit * lhs.y, unit * lhs.z);
}


