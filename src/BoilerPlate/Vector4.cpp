#include "Vector4.hpp"
#include <cmath>
Vector4::Vector4() {
}
Vector4::Vector4(float newX, float newY, float newZ, float newW) {
	x = newX;
	y = newY;
	z = newZ;
	w = newW;
}
Vector4::Vector4(float parametro) {
	x = parametro;
	y = parametro;
	z = parametro;
	w = parametro;
}
Vector4::Vector4(Vector2 vec2, float newZ, float newW) {
	x = vec2.x;
	y = vec2.y;
	z = newZ;
	w = newW;
}
Vector4::Vector4(Vector3 vec3, float newW) {
	x = vec3.x;
	y = vec3.y;
	z = vec3.z;
	w = newW;
}
float Vector4::Length() {
	return sqrt(x * x + y * y + z * z + w * w);
}
float Vector4::SquaredLength() {
	return x * x + y * y + z * z + w * w;
}
float Vector4::Normalize() {
	Length();
	// we get inverse Scale so we can multiply it to the factors this reducces the work for the cpu
	float inverseScale = 1.0 / length;
	x *= inverseScale;
	y *= inverseScale;
	z *= inverseScale;
	w *= inverseScale;

	return length;
}
////////////////////// OPERATORS //////////////////////////////////////////////////////////////////////////////
Vector4& Vector4::operator=(const Vector4& rhs) {
	if (this == &rhs) return *this;
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	w = rhs.w;

	return *this;
}
Vector4& Vector4::operator+=(const Vector4& rhs) {
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	w += rhs.w;

	return *this;
}
Vector4& Vector4::operator-=(const Vector4& rhs) {
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	w -= rhs.w;

	return *this;
}
Vector4& Vector4::operator*=(const Vector4& rhs) {
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	w *= rhs.w;

	return *this;
}
Vector4& Vector4::operator/=(const Vector4& rhs) {
	// si es 0; el divisor
	if (rhs.x == 0) throw " no se divide por 0";
	if (rhs.y == 0) throw " no se divide por 0";
	if (rhs.z == 0) throw " no se divide por 0";
	if (rhs.w == 0) throw " no se divide por 0";

	x = x / rhs.x;
	y = y / rhs.y;
	z = z / rhs.z;
	w = w / rhs.w;

	return *this;
}
Vector4 Vector4::operator+ (const Vector4& rhs) {
	return Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
}
Vector4 Vector4::operator- (const Vector4& rhs) {
	return Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
}
Vector4 Vector4::operator* (const Vector4& rhs) {
	return Vector4(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
}
Vector4 Vector4::operator/ (const Vector4& rhs) {
	if (rhs.x == 0) throw " no se divide por 0";
	if (rhs.y == 0) throw " no se divide por 0";
	if (rhs.z == 0) throw " no se divide por 0";
	if (rhs.w == 0) throw " no se divide por 0";

	return Vector4(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
}
bool Vector4::operator==(const Vector4& rhs) {
	return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w;
}
bool Vector4::operator!=(const Vector4& rhs) {
	return x == rhs.x || y == rhs.y || z == rhs.z || w == rhs.w;
}
Vector4 operator*(float unit, const Vector4& rhs) {
	return Vector4(unit * rhs.x, unit * rhs.y, unit * rhs.z, unit * rhs.w);
}
Vector4 operator*(const Vector4& lhs, float unit) {
	return Vector4(unit * lhs.x, unit * lhs.y, unit * lhs.z, unit * lhs.w);
}
