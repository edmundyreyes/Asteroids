#pragma once
struct Vector2;
struct Vector3
{
	/// static /////////////////////////////////////////////////

	static Vector3 Origin;

	/// constructores //////////////////////////////////////////

	Vector3();
	Vector3( float , float , float );
	Vector3( float );
	Vector3( const Vector2& );

	/// funciones //////////////////////////////////////////////

	float Length( );
	float SquaredLength( );
	float Normalize( );

	/// operadores /////////////////////////////////////////////

	Vector3&	   operator=  (const Vector3&);
	Vector3&	   operator+= (const Vector3&);
	Vector3&	   operator-= (const Vector3&);
	Vector3&	   operator*= (const Vector3&);
	Vector3&	   operator/= (const Vector3&);
	Vector3		   operator+  (const Vector3&);
	Vector3		   operator-  (const Vector3&);
	Vector3 	   operator*  (const Vector3&);
	Vector3		   operator/  (const Vector3&);
	bool           operator== (const Vector3&);
	bool           operator!= (const Vector3&);
	friend Vector3 operator*  (float, const Vector3&);
	friend Vector3 operator*  (const Vector3&, float);

	/// miembros ///////////////////////////////////////////////

	float x;
	float y;
	float z;
	float length;
};

