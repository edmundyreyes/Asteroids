#include "Bullet.hpp"
const float ORIGIN = 0.0f;
Bullet::Bullet(Player ship):
	Entity(4,4){
	bulletAngle = ship.angle;
	bulletLife = 120;

}
void Bullet::PushDrawEntity() {
	pointsContainer.push_back(Vector2(2,2));
	pointsContainer.push_back(Vector2(-2,2));
	pointsContainer.push_back(Vector2(-2,-2));
	pointsContainer.push_back(Vector2(2,-2));
	
}
void Bullet::Render() {
	glLoadIdentity();
	glTranslatef(position.x, position.y, ORIGIN);
}
