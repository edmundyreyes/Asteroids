#pragma once
#include "Vector4.hpp"
#include "MathUtilities.hpp"

#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include <vector>
#include <cmath>

class Entity
{
public:
	Entity();
	Entity(int , int);
	// members  ////////////////////////////////////////////////////////////////////

	std::vector<Vector2> pointsContainer;
	Vector2 position;
	Vector2 velocity;

	float mass;
	float maxWidth;
	float minWidth;
	float maxHeight;
	float minHeight;
	int radius;
	/// constr. //////////////////////////////////////////

	
	/// functions //////////////////////////////////////////////
	
	void Update				(float);
	virtual void Render			   	(void);	  
	virtual void ApplyImpulse	  (Vector2);
	void DrawEntity				(void);	   
	void calcMinMax(int, int);
	void DrawHollowCircle(void);



};

