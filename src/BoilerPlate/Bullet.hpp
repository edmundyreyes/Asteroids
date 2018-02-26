#pragma once
#include "Player.hpp"
class Bullet : public Entity{
public:
	Bullet(Player);
	void PushDrawEntity(void);
	void Render(void);




private:
	float bulletAngle;
	float bulletLife;
	
};
