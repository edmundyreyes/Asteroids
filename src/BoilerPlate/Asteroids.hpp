#pragma once
#include "Entity.hpp"

struct Asteroids : public Entity {
	// Size Options ////////////////////////////////////////////
	enum Asteroid_Size {
		SMALL_SIZE = 1,
		MEDIUM_SIZE = 2,
		BIG_SIZE = 3,
	};
	/// static /////////////////////////////////////////////////
	
	/// construc. //////////////////////////////////////////
	Asteroids(void);
	Asteroids(float , float );
	Asteroids( Asteroid_Size, float, float );

	/// functions //////////////////////////////////////////////

	void Update	(float);
	void Render (void);
	int  Asteroid_GetSize   (void);
	void PushDrawEntity		(void);
	void ApplyImpulse(Vector2) override;
	void MoveForward		(void);

	/// members ///////////////////////////////////////////////
	
	int asteroid_Size;
	float mass;
	float angle;
	bool moving;
	
};

