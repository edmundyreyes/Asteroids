#pragma once
#include "Asteroids.hpp"
#include "Player.hpp"

struct Game
{
	Game(void);
	void RenderGalaxy( void );
	void UpdateGalaxy( float );
	void CreateNewAsteroid(Asteroids);
	inline void ToggleDebuggTool() { deBuggtool = !deBuggtool; }
	void DrawAsteroidCircles(void);
	float CalculateDistance(Entity, Entity);
	bool DetectColision(Entity, Entity);
	void DeleteAsteroid(void);
	void RenderLines(Entity, Entity);
	void StartUpRoutine(Asteroids);

	// members
	std::vector<Asteroids> Galaxy;
	
	bool deBuggtool;
};

