#pragma once
#include "Vector2.h"
#include "Vector3.h"
class Vector4
{
public:
	//Constructores///////////////////////////////////

	Vector4();
	Vector4(float);
	Vector4(Vector3, float);
	Vector4(Vector2, float, float);
	Vector4(float, float, float, float);

	// Funciones       ///////////////////////////////

	float Length(void);
	float SquaredLength(void);
	float Normalize(void);

	// Operadores ////////////////////////////////////

	Vector4& operator=  (const Vector4& rhs);
	Vector4& operator+= (const Vector4& rhs);
	Vector4& operator-= (const Vector4& rhs);
	Vector4& operator*= (const Vector4& rhs);
	Vector4& operator/= (const Vector4& rhs);
	Vector4  operator+  (const Vector4& rhs);
	Vector4  operator-  (const Vector4& rhs);
	Vector4  operator*  (const Vector4& rhs);
	Vector4  operator/  (const Vector4& rhs);
	bool	 operator== (const Vector4& rhs);
	bool	 operator!= (const Vector4& rhs);
	friend Vector4 operator*(float, const Vector4&);
	friend Vector4 operator*(const Vector4&, float);

	// miembros   ////////////////////////////////////
	float x;
	float y;
	float z;
	float w;
	float length;
};