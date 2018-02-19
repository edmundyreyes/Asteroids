#pragma once
#include "Vector4.hpp"
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include <vector>

class Entity
{
public:
	// members  ///////////////////////////////////////////////
	Vector2 position;
	std::vector<Vector2> pointsContainer;

	/// constr. //////////////////////////////////////////
	Entity();
	/// functions //////////////////////////////////////////////
	
	void E_Update(void);
	void E_Render(void);
	void E_DrawEntity(void);
	void E_Warping(int, int);

};

