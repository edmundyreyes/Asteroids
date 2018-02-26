#pragma once
#include "Asteroids.hpp"
#include "Player.hpp"
#include "Bullet.hpp"

struct Game
{
	Game(void);
	void RenderGalaxy( void );
	void RenderMagazine(void);
	void UpdateGalaxy( float );
	void UpdateMagazine(float);
	void CreateNewAsteroid(float , float);
	void DrawAsteroidCircles(void);
	void DrawBulletCircle(void);
	float CalculateDistance(Entity, Entity);
	bool DetectColision(Entity, Entity);
	void DeleteAsteroid(void);
	void RenderLines(Entity, Entity);
	void StartUpRoutine(float, float);
	void ShootNewBullet(Player);
	inline void ToggleDebuggTool() { deBuggtool = !deBuggtool; }


	// members
	std::vector<Asteroids> Galaxy;
	std::vector<Bullet> Magazine;
	bool deBuggtool;
};

