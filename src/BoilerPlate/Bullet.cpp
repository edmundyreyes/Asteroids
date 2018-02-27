#include "Bullet.hpp"
const float ORIGIN = 0.0f;
const float SPACE_MAGIC = 30.0f;
const float MAX_SPEED = 600.0f;
const float BULLET_LIFE = 80;
const float BULLET_RADIUS = 5;

Bullet::Bullet() {}

Bullet::Bullet(Player ship):
	Entity(ship.maxWidth*2, ship.maxHeight*2) 
{
	bulletAngle = ship.angle;
	bulletLife = BULLET_LIFE;
	radius = BULLET_RADIUS;
	PushDrawEntity();
	mass = 0.4;
	velocity = Vector2(0, 0);
	position = Vector2(ship.position.x, ship.position.y);

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
	DrawEntity();

}
int Bullet::Getlife() {
	return bulletLife;
}
bool Bullet::GetisAlive() {
	return isAlive;
}

void Bullet::Update(float DT) {
	bulletLife--;
	ApplyImpulse(Vector2(SPACE_MAGIC, SPACE_MAGIC));
	float speed = sqrtf(velocity.x * velocity.x + velocity.y * velocity.y);
	MathUtilities math;
	if (speed > MAX_SPEED) {
		velocity.x = math.clamp(velocity.x, speed, MAX_SPEED);
		velocity.y = math.clamp(velocity.y, speed, MAX_SPEED);
		speed = MAX_SPEED;
	}
	Entity::Update(DT);
}
void Bullet::ApplyImpulse(Vector2 vecImpulse) {
	MathUtilities math;
	velocity.x += (vecImpulse.x / mass) * cos(math.degreesToRadians(bulletAngle + 90));
	velocity.y += (vecImpulse.y / mass) * sin(math.degreesToRadians(bulletAngle + 90));

}
