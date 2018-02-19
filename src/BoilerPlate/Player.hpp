#pragma once
#include "Vector2.hpp"
#include "MathUtilities.hpp"
#include "Entity.hpp"

// Externals
#include <GL/glew.h>
#include <cmath>
#include <SDL2/SDL_opengl.h>
#include <vector>

struct Player : public Entity {
	/// static /////////////////////////////////////////////////

	static Player Origin;

	/// constr. //////////////////////////////////////////

	Player();
	Player(float , float );
	Player(Vector2);

	/// functions //////////////////////////////////////////////
	
	void renderPlayer(void);
	void moveForward(void);
	void rotateLeft(void);
	void rotateRight(void);
	void Update(float, float);
	void PushDrawEntity(void);
	void PushDrawThruster(void);
	void DrawThruster(void);

	/// members ///////////////////////////////////////////////

	float mass;
	float angle;
	int screenWidth;
	int screenHeight;
	bool trushterBool;
	std::vector <Vector2> pointsThruster;
	
};