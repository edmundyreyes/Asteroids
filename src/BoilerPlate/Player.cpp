#include "Player.hpp"

const float THRUST = 60.0f;
const float MAX_SPEED = 350.0f;
const float ANGLE_ROTATE = 3.0f;
const float DRAG_FORCE = 0.91f;
const float ZERO = 0.0f;
const float SHIPS_RADIUS = 17;
float timer = 0.0;


/////// Constructors //////////////////////////////////////////////////////////////////////

Player::Player() {}

Player::Player(float width, float height):
	Entity(width,height) {

	live = true;
	stocks = 3;
	trushterBool = false;
	moving = false;
	angle  = ZERO;
	radius = SHIPS_RADIUS;
	position = Vector2(ZERO, ZERO);
	velocity = Vector2(ZERO, ZERO);
	PushDrawEntity();
	PushDrawThruster();

}

/////// Functions for Motion //////////////////////////////////////////////////////////////////////
void Player::ApplyImpulse(Vector2 vecImpulse) {

	MathUtilities math;
	velocity.x += (vecImpulse.x ) * cos(math.degreesToRadians(angle + 90));
	velocity.y += (vecImpulse.y ) * sin(math.degreesToRadians(angle + 90));


}
void Player::RotateLeft() {
	angle += ANGLE_ROTATE;
}
void Player::RotateRight() {
	angle -= ANGLE_ROTATE;
}
void Player::MoveForward() {
	trushterBool = true;
	moving = true;
	ApplyImpulse(Vector2(THRUST,THRUST));
		
}

/////// Thruster //////////////////////////////////////////////////////////////////////

void Player::DrawThruster() {
	if (trushterBool) {
		glColor3f(1, 0, 0);
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

void Player::Update(float DT) {
	
	if (!moving) trushterBool = false;
	float speed = sqrtf(velocity.x * velocity.x + velocity.y * velocity.y);
	MathUtilities math;

	if (speed > MAX_SPEED) {

		velocity.x = math.clamp(velocity.x, speed, MAX_SPEED);
		velocity.y = math.clamp(velocity.y, speed, MAX_SPEED);
		speed = MAX_SPEED;
	}
	if (moving) {
		velocity.x *= DRAG_FORCE;
		velocity.y *= DRAG_FORCE;
	}
	currentSpeed = speed;
	Invulnerablity(DT);

	Entity::Update(DT);
}
void Player::PushDrawEntity() {
	pointsContainer.push_back(Vector2(0, 20));
	pointsContainer.push_back(Vector2(12, -10));
	pointsContainer.push_back(Vector2(6, -4));
	pointsContainer.push_back(Vector2(-6, -4));
	pointsContainer.push_back(Vector2(-12, -10));
}
void Player::Render() {
	if (stocks > 0 && live) {
		glLoadIdentity();
		glColor3f(0, 0.5, 0.5);
		glTranslatef(position.x, position.y, ZERO);
		glRotatef(angle, ZERO, ZERO, 1);
		DrawEntityPolygon();
		DrawThruster();
	}
}
void Player::Killit() {
	stocks--;
	live = false;
	position.x = ZERO;
	position.y = ZERO;
	velocity.x = ZERO;
	velocity.y = ZERO;
	angle = ZERO;
}
void Player::Invulnerablity(float DT) {
	if (!live) {
		timer += DT;
		cout << timer << endl;
		if (timer >= 2) {
			live = true;
			timer = 0;
		}
	}
}
bool Player::GetLive() {
	return live;
}
void Player::SetLive(bool status) {
	live = status;
}
int Player::GetStocks() {
	return stocks;
}
void Player::SetStocks(int numberOfLife ) {
	stocks = numberOfLife;
}
