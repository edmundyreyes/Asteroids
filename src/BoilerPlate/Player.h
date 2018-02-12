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
	
	void renderPlayer(void);
	void renderThruster();
	void Warping(void);
	void moveForward(void);
	void rotateLeft(void);
	void rotateRight(void);
	void Move(float , float);

	/// miembros ///////////////////////////////////////////////
	Vector2 jugador;
	bool trushterBool;
};