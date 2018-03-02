#include "Asteroids.hpp"
const float SPACE_MAGIC = 30.0f;
const float MAX_SPEED = 60.0f;
const float ASTEROID_RADIO = 27.0f;
const float ASTEROID_ADVANCE_METERS = 10.0f;
const float STARTING_ASTEROID_ANGLE = 30.0f;
const float ZERO = 0.0f;
const float ASTEROID_ROTATE_SPEED = 0.3f;
float ASTEROID_ROTATE_ANGLE = 0.0f;


Asteroids::Asteroids() {}
Asteroids::Asteroids(float width,float height):
	Entity(width,height) {

	m_Asteroid_Size = 3;
	m_Angle = STARTING_ASTEROID_ANGLE;
	PushDrawEntity();
	m_Mass = (float)(m_Asteroid_Size);
	position = Vector2((float)(rand()%1000), (float)(rand()%1000));
	velocity = Vector2(ZERO, ZERO);
	m_radius = m_Asteroid_Size * ASTEROID_RADIO;
}
Asteroids::Asteroids(Asteroid_Size size, float width, float height):
	Entity(width, height) {
	m_Angle = STARTING_ASTEROID_ANGLE;
	m_Asteroid_Size = size; 
	m_Mass = (float)(m_Asteroid_Size);
	PushDrawEntity();
	position = Vector2((float)(rand() % 1000), (float)(rand() % 1000));
	velocity = Vector2(ZERO, ZERO);
	m_radius = m_Asteroid_Size * ASTEROID_RADIO;
}
Asteroids::Asteroids(Asteroid_Size size, Asteroids rock) :
	Entity(rock.m_maxWidth * 2, rock.m_maxHeight * 2) {
	m_Angle = rock.m_Angle + rand() % 360;
	m_Asteroid_Size = size;
	m_Mass = (float)(m_Asteroid_Size);
	PushDrawEntity();
	position = Vector2(rock.position.x,rock.position.y);
	velocity = Vector2(ZERO, ZERO);
	m_radius = (float)(m_Asteroid_Size) * ASTEROID_RADIO;
}
int Asteroids::Asteroid_GetSize() {
	return m_Asteroid_Size;
}
void Asteroids::Update( float DT ) {
	ASTEROID_ROTATE_ANGLE += ASTEROID_ROTATE_SPEED;
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
void Asteroids::PushDrawEntity() {
	int size = Asteroid_GetSize();
	// The numbers inside the Vector2 are the points of the Asteroids
	//  those are rendering using the vector, pointsContainer.
	// multiply it by the size and you get the Draw for the Asteroid.
	pointsContainer.push_back(Vector2(-26.0f * size, 6.0f  * size));//a
	pointsContainer.push_back(Vector2(-9.0f  * size, 18.0f  * size));//b
	pointsContainer.push_back(Vector2( 12.0f  * size, 20.0f  * size));//c
	pointsContainer.push_back(Vector2( 28.0f  * size, 9.0f   * size));//d
	pointsContainer.push_back(Vector2( 28.0f  * size,-13.0f  * size));//e
	pointsContainer.push_back(Vector2( 13.0f   * size, -27.0f  * size));//f
	pointsContainer.push_back(Vector2(-4.0f  * size,-32.0f  * size));//g
	pointsContainer.push_back(Vector2( -19.0f  * size, -26.0f  * size));//h
	pointsContainer.push_back(Vector2(-30.0f  * size, -20.0f  * size));//i
	pointsContainer.push_back(Vector2(-33.0f  * size,-10.0f  * size));//j
}
void Asteroids::ApplyImpulse(Vector2 vecImpulse) {
	MathUtilities math;
	velocity.x += (vecImpulse.x / m_Mass) * cos(math.DegreesToRadians(m_Angle));
	velocity.y += (vecImpulse.y / m_Mass) * sin(math.DegreesToRadians(m_Angle));

}
void Asteroids::Render() {
	glLoadIdentity();
	glTranslatef(position.x, position.y, 0.0f);
	glRotatef(ASTEROID_ROTATE_ANGLE, 0.0f, 0.0f, 1.0f);
	DrawEntity();
}