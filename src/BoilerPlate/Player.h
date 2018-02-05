#pragma once
#include "Vector2.h"
struct Player
{
	/// static /////////////////////////////////////////////////
	static Player Origin;
	/// constructores //////////////////////////////////////////
	Player();
	Player(float);
	Player(float , float );
	Player(Vector2);
	/// funciones //////////////////////////////////////////////
	
	void playerUp();
	void playerDown();
	void playerLeft();
	void playerRight();
	float showX();
	float showY();
	void renderPlayer();
	/// miembros ///////////////////////////////////////////////
	Vector2 jugador;
};