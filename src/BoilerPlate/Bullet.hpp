#pragma once
#include "Player.hpp"
class Bullet : public Entity{
public:
	Bullet();
	Bullet(Player);
	void PushDrawEntity(void);
	void Render(void);
	void Update(float DT);
	void ApplyImpulse(Vector2 vecImpulse);
	int Getlife(void);
	bool GetisAlive(void);


private:
	float bulletAngle;
	float bulletLife;
	bool isAlive;

};
