#pragma once
#include "Asteroids.hpp"
#include "Player.hpp"
#include "Bullet.hpp"
#include "InputManager.hpp"
#include "TextManager.hpp"
#include <string>

struct Game
{
	Game						 (float,float);
	void RenderGalaxy					(void);
	void RenderMagazine					(void);
	void DrawAsteroidCircles			(void);
	void DrawBulletCircle				(void);
	void Fps							(void);
	void DeleteAsteroid					(void);
	void BulletCollision				(void);
	void Update							(float, Player&);
	void UpdateGalaxy					(float);
	void UpdateMagazine					(float);
	bool CheckCollisionWithMagazine		(Asteroids);
	void ShipCollision					(Player &);
	void DebugMode						(Player);
	void Render							(Player);
	void ShootNewBullet					(Player);
	bool KillBullet						(Bullet);
	void StartUpRoutine					(float, float);
	void CreateNewAsteroid				(float, float);
	float CalculateDistance				(Entity, Entity);
	bool DetectColision					(Entity, Entity);
	void RenderLines					(Entity, Entity);
	inline void ToggleDebuggTool		(void) { m_debuggTool = !m_debuggTool; }

	void InitGameFontColor(int, int, int, int);
	void RenderGameGUI(Player ship);


	// members
	std::vector<Asteroids> m_Galaxy;
	std::vector<Bullet> m_Magazine;
	std::vector<float> m_Framerates;
	bool m_debuggTool;
	int m_time;
	int m_score;
	TextManager m_textRenderer;
	TTF_Font *m_GameFont;
	SDL_Color m_GameFontColor;
	float m_width;
	float m_height;
	
};

