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

	float m_mass;
	float m_maxWidth;
	float m_minWidth;
	float m_maxHeight;
	float m_minHeight;
	float m_radius;
	/// constr. //////////////////////////////////////////

	
	/// functions //////////////////////////////////////////////
	
	void Update						   (float);
	virtual void Render			   		(void);	  
	virtual void ApplyImpulse		 (Vector2);
	void DrawEntity						(void);	
	void DrawEntityPolygon				(void);
	void CalcMinMaxWidthHeight				(float, float);
	void DrawHollowCircle				(void);
	void OnResize				(float, float);



};

