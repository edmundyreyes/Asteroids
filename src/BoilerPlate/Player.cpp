#include "Player.h"

#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

Vector2 parametroX = Vector2(10,0);
Vector2 parametroY = Vector2(0,10);
int screenWidth = 570;
int screenHeight = 330;
Player Player::Origin = Player();

Player::Player()
{
}
Player::Player(float num) {
	jugador = Vector2(num, num);
}
Player::Player(float newx, float newy) {
	jugador = Vector2(newx, newy);
}
Player::Player(Vector2 vec) {
	jugador = vec;
}
void Player::Move(float _x, float _y) {
	Vector2 movement = Vector2(_x, _y);
	jugador += movement;
	Warping();
}
void Player::Warping() {

	//Update();
	if (jugador.x < -screenWidth) {
		jugador.x = screenWidth;
	}
	else if (jugador.x > screenWidth)
		jugador.x = -screenWidth;

	if (jugador.y < -screenHeight) {
		jugador.y = screenHeight;
	}
	else if (jugador.y > screenHeight)
		jugador.y = -screenHeight;
}

void Player::moveForward() {}

void Player::rotateLeft() {}

void Player::rotateRight() {}

void Player::renderThruster() {
	if (trushterBool) {
		glBegin(GL_LINE_LOOP);
		glVertex2f(-5.0 + jugador.x, -4.0 + jugador.y);
		glVertex2f(5.0 + jugador.x, -4.0 + jugador.y);
		glVertex2f(0.0 + jugador.x, -15.0 + jugador.y);
		glEnd();
	}
}
void Player::renderPlayer() {
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 0.55f, 0.50f);
	glVertex2f(0 + jugador.x, 20 + jugador.y);
	glVertex2f(12 + jugador.x, -10 + jugador.y);
	glVertex2f(6 + jugador.x, -4 + jugador.y);
	glVertex2f(-6 + jugador.x, -4 + jugador.y);
	glVertex2f(-12 + jugador.x, -10 + jugador.y);
	glEnd();
}