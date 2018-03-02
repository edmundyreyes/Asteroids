#pragma once
#include "Asteroids.hpp"
#include "Player.hpp"
#include "Bullet.hpp"
#include "InputManager.hpp"
#include "TextManager.hpp"
#include <string>

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
	void Update							(float, Player&);
	void UpdateGalaxy					(float);
	void UpdateMagazine					(float);
	bool CheckCollisionWithMagazine		(Asteroids);
	void ShipCollision					(Player &);
	void DebugMode						(Player);
	void ShootNewBullet					(Player);
	bool KillBullet						(Bullet);
	void StartUpRoutine					(float, float);
	void CreateNewAsteroid				(float, float);
	float CalculateDistance				(Entity, Entity);
	bool DetectColision					(Entity, Entity);
	void RenderLines					(Entity, Entity);
	inline void ToggleDebuggTool		(void) { debuggTool = !debuggTool; }
	void InitGameFontColor(int, int, int, int);
	void RenderGameGUI();


	// members
	std::vector<Asteroids> Galaxy;
	std::vector<Bullet> Magazine;
	std::vector<float> Framerates;
	bool debuggTool;
	int time;
	int score;
	TextManager textRenderer;
	TTF_Font *gameFont;
	SDL_Color gameFontColor;
	
};

