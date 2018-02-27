#include "Asteroids.hpp"
const float SPACE_MAGIC = 30.0f;
const float MAX_SPEED = 60.0f;
const float ASTEROID_RADIO = 27.0f;

Asteroids::Asteroids() {}
Asteroids::Asteroids(float width,float height):
	Entity(width,height) {

	asteroid_Size = 3;
	angle = 30;
	PushDrawEntity();
	mass = asteroid_Size;
	position = Vector2(rand() % 1000, rand() % 1000);
	velocity = Vector2(0, 0);
	radius = asteroid_Size * ASTEROID_RADIO;
}
Asteroids::Asteroids(Asteroid_Size size, float width, float height):
	Entity(width, height) {
	angle = 0;
	asteroid_Size = size; 
	mass = asteroid_Size;
	PushDrawEntity();
	position = Vector2(rand() % 1000, rand() % 1000);
	velocity = Vector2(0, 0);
	radius = asteroid_Size * ASTEROID_RADIO;
}
Asteroids::Asteroids(Asteroid_Size size, Asteroids rock) :
	Entity(rock.maxWidth * 2, rock.maxHeight * 2) {
	angle = rock.angle + 100;
	asteroid_Size = size;
	mass = asteroid_Size;
	PushDrawEntity();
	position = Vector2(rock.position.x,rock.position.y);
	velocity = Vector2(0, 0);
	radius = asteroid_Size * ASTEROID_RADIO;
}


int Asteroids::Asteroid_GetSize() {
	return asteroid_Size;
}

void Asteroids::Update( float DT ) {
	ApplyImpulse(Vector2(SPACE_MAGIC, SPACE_MAGIC));
	Entity::Update(DT);
	float speed = sqrtf(velocity.x * velocity.x + velocity.y * velocity.y);
	MathUtilities math;
	if (speed > MAX_SPEED) {
		velocity.x = math.clamp(velocity.x, speed, MAX_SPEED);
		velocity.y = math.clamp(velocity.y, speed, MAX_SPEED);
		speed = MAX_SPEED;
	}
}

void Asteroids::PushDrawEntity() {
	int size = Asteroid_GetSize();

	pointsContainer.push_back(Vector2(-20 * size, 20 * size));//b
	pointsContainer.push_back(Vector2(-5 * size, 20 * size));//h
	pointsContainer.push_back(Vector2( 12 * size, 22 * size));//c
	pointsContainer.push_back(Vector2( 24 * size, 5  * size));//a
	pointsContainer.push_back(Vector2( 26 * size,-21 * size));//d
	pointsContainer.push_back(Vector2( 9  * size, -20 * size));//e
	pointsContainer.push_back(Vector2(-10 * size,-30 * size));//f
	pointsContainer.push_back(Vector2( -8 * size, -8 * size));//g
	pointsContainer.push_back(Vector2(-20 * size, -14 * size));//i
	pointsContainer.push_back(Vector2(-33 * size,-10 * size));//t
}

void Asteroids::ApplyImpulse(Vector2 vecImpulse) {
	MathUtilities math;
	velocity.x += (vecImpulse.x / mass) * cos(math.degreesToRadians(angle));
	velocity.y += (vecImpulse.y / mass) * sin(math.degreesToRadians(angle));

}

void Asteroids::Render() {
	glLoadIdentity();
	glTranslatef(position.x, position.y, 0.0f);

	DrawEntity();
}