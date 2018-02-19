#include "Asteroids.hpp"
Asteroids::Asteroids(){
	asteroid_Size = 1;
	PushDrawEntity();
}

int Asteroids::Asteroid_GetSize() {
	return asteroid_Size;
}

void Asteroids::Asteroid_Update() {}

void Asteroids::PushDrawEntity() {
	int size = Asteroid_GetSize();

	pointsContainer.push_back(Vector2(-20 * size, 20 * size));
	pointsContainer.push_back(Vector2( 12 * size, 22 * size));
	pointsContainer.push_back(Vector2( 24 * size, 5  * size));
	pointsContainer.push_back(Vector2( 26 * size,-21 * size));
	pointsContainer.push_back(Vector2(-10 * size,-30 * size));
	pointsContainer.push_back(Vector2( -8 * size, -8 * size));
	pointsContainer.push_back(Vector2(-33 * size,-10 * size));
}
Asteroids::Asteroids(Asteroid_Size size){
	asteroid_Size = size;
	PushDrawEntity();
}
