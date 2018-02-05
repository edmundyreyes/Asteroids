#pragma once
#define _VECTOR2_H_

struct Vector2
{
	public:

		static Vector2 Origin;

		//Constructores///////////////////////////////////
	
		Vector2();
		Vector2(float, float );
		Vector2(float);
	
		// Funciones       ///////////////////////////////
	
		float Length() ;
		float SquaredLength() ;
		float Normalize();

		// Operadores ////////////////////////////////////
	
		Vector2& operator=  (const Vector2& rhs);
		Vector2& operator+= (const Vector2& rhs);
		Vector2& operator-= (const Vector2& rhs);
		Vector2& operator*= (const Vector2& rhs);
		Vector2& operator/= (const Vector2& rhs);
		Vector2 operator+  (const Vector2& rhs);
		Vector2 operator-  (const Vector2& rhs);
		Vector2 operator*  (const Vector2& rhs);
		Vector2 operator/  (const Vector2& rhs);
		bool	 operator== (const Vector2& rhs);
		bool	 operator!= (const Vector2& rhs); 
		friend Vector2 operator*(float, const Vector2&);
		friend Vector2 operator*(const Vector2&, float);

		// miembros   ////////////////////////////////////
	
		float x;
		float y;
		float length;
};

