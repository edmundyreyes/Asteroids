#pragma once
#include "Vector4.hpp"
#include "Entity.hpp"
#include <vector>
struct Asteroids : public Entity {
	// Size Options ////////////////////////////////////////////
	enum Asteroid_Size {
		SMALL_SIZE = 1,
		MEDIUM_SIZE = 2,
		BIG_SIZE = 3,
	};
	/// static /////////////////////////////////////////////////
	
	/// construc. //////////////////////////////////////////

	Asteroids		  ( void );
	Asteroids( Asteroid_Size );

	/// functions //////////////////////////////////////////////

	void Asteroid_Update	(void);
	int  Asteroid_GetSize   (void);
	void PushDrawEntity		(void);

	/// members ///////////////////////////////////////////////
	int asteroid_Size;
	
};

