#include <iostream>
#include <String.h>
using namespace std;
class MathUtilities
{
public:
	///// constructores /////////////////////////////////////////

	MathUtilities();
	
	///// Funciones ///////////////////////////////////////////////
	
	int floatToInt					 (float );
	int floatToEven					 (float );
	float clamp			 (float , int , int );
	float degreesToRadians			  ( int );
	int radiansToDegrees			( float );
	int radiansDistance		( float , float );
	int angularDistance			( int , int );
	bool isAPowerOfTwo				  ( int );
	float interpolate(float , float , float );

	///  Funciones con Templates  ////////////////////////////////////////////////

	template <class data>
	data getMin(data num1, data num2) {
		if (num1 <= num2) return num1
		else return num2;
	}
	template <class data>
	data getMin(data num1, data num2, data num3) {
		if (num1 <= num2) {
			if (num1 <= num3) return num1;
			else return num3;
		}
		else {
			if (num2 <= num3) return num2;
			else return num3;
		}
	}
	template <class data>
	data getMin(data num1, data num2, data num3, data num4) {
		if (num1 <= num2) {
			if (num3 <= num4) {
				if (num1 <= num3) return num1;
				else return num3;
			}
			else {
				if (num1 <= num4) return num1;
				else return num4;
			}
		}
		else {
			if (num3 <= num4) {
				if (num2 <= num3) return num2;
				else return num3;
			}
			else {
				if (num2 <= num4) return num2;
				else return num4;
			}
		}
	}
	template <class data>
	data getMax(data num1, data num2) {
		if (num1 >= num2) return num1
		else return num2;
	}
	template <class data>
	data getMax(data num1, data num2, data num3) {
		if (num1 >= num2) {
			if (num1 >= num3) return num1;
			else return num3;
		}
		else {
			if (num2 >= num3) return num2;
			else return num3;
		}
	}
	template <class data>
	data getMax(data num1, data num2, data num3, data num4) {
		if (num1 >= num2) {
			if (num3 >= num4) {
				if (num1 >= num3) return num1;
				else return num3;
			}
			else {
				if (num1 >= num4) return num1;
				else return num4;
			}
		}
		else {
			if (num3 >= num4) {
				if (num2 >= num3) return num2;
				else return num3;
			}
			else {
				if (num2 >= num4) return num2;
				else return num4;
			}
		}
	}

	//// miembros /////////////////////////////////////////////////
	
	static float PI;
};

