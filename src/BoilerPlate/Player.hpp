#pragma once
#include "Entity.hpp"
#include "Asteroids.hpp"


struct Player : public Entity {
	/// static /////////////////////////////////////////////////

	static Player Origin;

	/// constr. //////////////////////////////////////////

	Player();
	Player(float , float );

	/// functions //////////////////////////////////////////////
	
	void Render(void) override;
	void MoveForward(void);
	void RotateLeft(void);
	void RotateRight(void);

	void Update( float );
	void PushDrawEntity(void);
	void PushDrawThruster(void);
	void DrawThruster(void);

	void ApplyImpulse(Vector2) override;
	inline void ToggleMove() { moving = !moving; }
	
	
	/// members ///////////////////////////////////////////////

	float mass;
	float angle;
	int screenWidth;
	int screenHeight;
	bool trushterBool;
	
	std::vector <Vector2> pointsThruster;

	bool moving;
	float currentSpeed;
};