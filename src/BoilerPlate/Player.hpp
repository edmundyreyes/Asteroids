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
	inline void ToggleMove() { m_moving = !m_moving; }
	inline void ToggleLive() { m_Live = !m_Live; }

	void SetLive(bool);
	void Killit(void);
	float GetStocks(void);
	void PlusStock();
	void DisplayLives(void);
	void TimeDead(float);
	
	/// members ///////////////////////////////////////////////

	float m_Mass;
	float m_angle;
	bool m_moving;
	bool m_TrushterBool;
	float m_CurrentSpeed;
	std::vector <Vector2> pointsThruster;
	float m_LifeSoFar;

private:
	float m_Stocks;
	bool m_Live;
};