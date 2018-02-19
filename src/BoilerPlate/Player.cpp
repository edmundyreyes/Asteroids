#include "Player.hpp"

Player Player::Origin = Player();

/////// Constructors //////////////////////////////////////////////////////////////////////

Player::Player() {
	angle = 0.0f;
	mass = 0.0f;
	trushterBool = false;
	PushDrawEntity();
	PushDrawThruster();
}
Player::Player(Vector2 vec) {
	position = vec;
	angle = 0;
}
Player::Player(float newx, float newy) {
	position = Vector2(newx, newy);
	angle = 0;
}

/////// Functions for Motion //////////////////////////////////////////////////////////////////////
void Player::rotateLeft() {
	angle += 10;
}
void Player::rotateRight() {
	angle -= 10;
}
void Player::moveForward() {
	MathUtilities math;

	position.x -= 10 * sin(math.degreesToRadians(angle));
	position.y += 10 * cos(math.degreesToRadians(angle));
	E_Warping(screenWidth, screenHeight);
}
/////// Thruster //////////////////////////////////////////////////////////////////////

void Player::DrawThruster() {
	if (trushterBool) {
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < pointsThruster.size(); i++) {
			glVertex2f(pointsThruster[i].x, pointsThruster[i].y);
		}
		glEnd();
	}
}
void Player::PushDrawThruster() {
	pointsThruster.push_back(Vector2(-5,-4));
	pointsThruster.push_back(Vector2(5,-4));
	pointsThruster.push_back(Vector2(0,-15));
}
/////// Others  //////////////////////////////////////////////////////////////////////

void Player::Update(float _screenWidth, float _screenHeight) {
	screenHeight = _screenHeight;
	screenWidth  =  _screenWidth;
}
void Player::PushDrawEntity() {
	pointsContainer.push_back(Vector2(0, 20));
	pointsContainer.push_back(Vector2(12, -10));
	pointsContainer.push_back(Vector2(6, -4));
	pointsContainer.push_back(Vector2(-6, -4));
	pointsContainer.push_back(Vector2(-12, -10));
}
void Player::renderPlayer() {
	glLoadIdentity();
	glTranslatef(position.x, position.y, 0);
	glRotatef(angle, 0, 0, 1);

	E_DrawEntity();
	DrawThruster();
}