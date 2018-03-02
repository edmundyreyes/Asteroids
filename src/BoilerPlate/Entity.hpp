#pragma once
#include "Vector4.hpp"
#include "MathUtilities.hpp"

#include <GL/glew.h>
#include <SDL_opengl.h>
#include <vector>
#include <cmath>
#include <irrKlang.h> 

class Entity
{
public:
	Entity();
	Entity(float , float);
	// members  ////////////////////////////////////////////////////////////////////

	std::vector<Vector2> pointsContainer;
	Vector2 position;
	Vector2 velocity;

	float mass;
	float maxWidth;
	float minWidth;
	float maxHeight;
	float minHeight;
	float radius;
	/// constr. //////////////////////////////////////////

	
	/// functions //////////////////////////////////////////////
	
	void Update						   (float);
	virtual void Render			   		(void);	  
	virtual void ApplyImpulse		 (Vector2);
	void DrawEntity						(void);	
	void DrawEntityPolygon				(void);
	void CalcMinMax				(float, float);
	void DrawHollowCircle				(void);
	void OnResize				(float, float);



};

