#pragma once
#include "Asteroids.hpp"
#include "Player.hpp"
#include "Bullet.hpp"

struct Game
{
	Game(void);
	void RenderGalaxy					(void);
	void RenderMagazine					(void);
	void DrawAsteroidCircles			(void);
	void DrawBulletCircle				(void);
	void Render							(void);
	void Fps							(void);
	void DeleteAsteroid					(void);
	void BulletCollision				(void);
	void Update							(float);
	void UpdateGalaxy					(float);
	void UpdateMagazine					(float);
	bool CheckCollisionWithMagazine		(Asteroids);
	void ShipCollision					(Player);
	void DebugMode						(Player);
	void ShootNewBullet					(Player);
	bool KillBullet						(Bullet);
	void StartUpRoutine					(float, float);
	void CreateNewAsteroid				(float, float);
	float CalculateDistance				(Entity, Entity);
	bool DetectColision					(Entity, Entity);
	void RenderLines					(Entity, Entity);
	inline void ToggleDebuggTool		(void) { debuggTool = !debuggTool; }


	// members
	std::vector<Asteroids> Galaxy;
	std::vector<Bullet> Magazine;
	std::vector<float> Framerates;
	bool debuggTool;
	int time;
	
};

