#include "Player.h"

#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

Vector2 parametroX = Vector2(10,0);
Vector2 parametroY = Vector2(0,10);

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
void Player::playerUp() {
	jugador += parametroY;
}
void Player::playerDown() {
	jugador -= parametroY;
}
void Player::playerLeft() {
	jugador -= parametroX;
}
void Player::playerRight() {
	jugador += parametroX;
}
float Player::showX() {
	return jugador.x;
}
float Player::showY() {
	return jugador.y;
}
//started value, positive and negative
float stVp = 25, stVn = -25;
void Player::renderPlayer() {
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 0.55f, 0.50f);
	glVertex2f(stVp + showX(), stVp + showY());
	glVertex2f(stVp + showX(), stVn + showY());
	glVertex2f(stVn + showX(), stVp + showY());
	glVertex2f(stVn + showX(), stVn + showY());
	glEnd();
}