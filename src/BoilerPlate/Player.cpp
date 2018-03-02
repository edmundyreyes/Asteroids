#include "Player.hpp"

const float THRUST = 60.0f;
const float MAX_SPEED = 350.0f;
const float ANGLE_ROTATE = 3.0f;
const float DRAG_FORCE = 0.91f;
const float ZERO = 0.0f;
const float SHIPS_RADIUS = 17;
const float STARTING_STOCKS = 3;
const float FIXING_ANGLE = 90;
float timer = 0.0;


/////// Constructors //////////////////////////////////////////////////////////////////////

Player::Player() {}

Player::Player(float width, float height):
	Entity(width,height) {

	m_Live = true;
	m_moving = false;
	m_TrushterBool = false;
	m_angle  = ZERO;
	m_LifeSoFar = ZERO;
	PushDrawEntity();
	PushDrawThruster();
	m_radius = SHIPS_RADIUS;
	m_Stocks = STARTING_STOCKS;
	position = Vector2(ZERO, ZERO);
	velocity = Vector2(ZERO, ZERO);

}

/////// Functions for Motion //////////////////////////////////////////////////////////////////////
void Player::ApplyImpulse(Vector2 vecImpulse) {

	MathUtilities math;
	velocity.x += (vecImpulse.x ) * cos(math.DegreesToRadians(m_angle + FIXING_ANGLE));
	velocity.y += (vecImpulse.y ) * sin(math.DegreesToRadians(m_angle + FIXING_ANGLE));
}
void Player::RotateLeft() {
	m_angle += ANGLE_ROTATE;
}
void Player::RotateRight() {
	m_angle -= ANGLE_ROTATE;
}
void Player::MoveForward() {
	m_TrushterBool = true;
	m_moving = true;
	ApplyImpulse(Vector2(THRUST,THRUST));
		
}

/////// Thruster //////////////////////////////////////////////////////////////////////

void Player::DrawThruster() {
	if (m_TrushterBool) {
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
	
	if (!m_moving) m_TrushterBool = false;
	float speed = sqrtf(velocity.x * velocity.x + velocity.y * velocity.y);
	MathUtilities math;
	m_LifeSoFar += DT;
	if (speed > MAX_SPEED) {

		velocity.x = math.Clamp(velocity.x, speed, MAX_SPEED);
		velocity.y = math.Clamp(velocity.y, speed, MAX_SPEED);
		speed = MAX_SPEED;
	}
	if (m_moving) {
		velocity.x *= DRAG_FORCE;
		velocity.y *= DRAG_FORCE;
	}
	m_CurrentSpeed = speed;
	TimeDead(DT);

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
	if (m_Stocks > 0 && m_Live) {
		glLoadIdentity();
		glColor3f(0, 0.5, 0.5);
		glTranslatef(position.x, position.y, ZERO);
		glRotatef(m_angle, ZERO, ZERO, 1);
		DrawEntityPolygon();
		DrawThruster();
		DisplayLives();
	}
}
void Player::Killit() {
	m_Stocks--;
	m_Live = false;
	position.x = ZERO;
	position.y = ZERO;
	velocity.x = ZERO;
	velocity.y = ZERO;
	m_LifeSoFar = ZERO;
	m_angle = ZERO;
}
void Player::TimeDead(float DT) {
	if (!m_Live) {
		timer += DT;
		if (timer >= 2) {
			m_Live = true;
			timer = 0;
		}
	}
}
bool Player::GetLive() {
	return m_Live;
}
void Player::SetLive(bool status) {
	m_Live = status;
}
float Player::GetStocks() {
	return m_Stocks;
}
void Player::PlusStock() {
	m_Stocks ++;
}
void Player::DisplayLives() {
	float life_factor = 1;
	for (int i = 0; i < m_Stocks; i++) {
		float xAxis = m_maxWidth - 40 * life_factor;
		float yAxis = m_maxHeight  - 80;
		glLoadIdentity();
		glTranslatef(xAxis , yAxis , 0.0f);
		DrawEntity();
		life_factor++;
	}
}
