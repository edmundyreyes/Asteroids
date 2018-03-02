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
	bool GetLive(void);

	void ApplyImpulse(Vector2) override;
	inline void ToggleMove() { moving = !moving; }
	inline void ToggleLive() { live = !live; }

	void SetLive(bool);
	void Killit(void);
	int GetStocks(void);
	void SetStocks(int);
	
	/// members ///////////////////////////////////////////////

	float mass;
	float angle;
	bool moving;
	int screenWidth;
	int screenHeight;
	bool trushterBool;
	float currentSpeed;
	void Invulnerablity(float);
	std::vector <Vector2> pointsThruster;

private:
	int stocks;
	bool live;
};