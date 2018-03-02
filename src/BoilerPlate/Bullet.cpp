#include "Bullet.hpp"
const float ZERO = 0.0f;
const float SPACE_MAGIC = 30.0f;
const float MAX_SPEED = 600.0f;
const float BULLET_LIFE = 80.0f;
const float BULLET_RADIUS = 5.0f;
const float BULLET_MASS = 0.4f;

Bullet::Bullet() {}

Bullet::Bullet(Player ship):
	Entity(ship.maxWidth*2, ship.maxHeight*2) 
{
	bulletAngle = ship.angle;
	bulletLife = BULLET_LIFE;
	radius = BULLET_RADIUS;
	PushDrawEntity();
	mass = BULLET_MASS;
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
	glTranslatef(position.x, position.y, ZERO);
	DrawEntity();

}
float Bullet::Getlife() {
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
		velocity.x = math.Clamp(velocity.x, speed, MAX_SPEED);
		velocity.y = math.Clamp(velocity.y, speed, MAX_SPEED);
		speed = MAX_SPEED;
	}
	Entity::Update(DT);
}
void Bullet::ApplyImpulse(Vector2 vecImpulse) {
	MathUtilities math;
	velocity.x += (vecImpulse.x / mass) * cos(math.DegreesToRadians(bulletAngle + 90));
	velocity.y += (vecImpulse.y / mass) * sin(math.DegreesToRadians(bulletAngle + 90));

}
