#include "Entity.hpp"
/////// Constructors //////////////////////////////////////////////////////////////////////
Entity::Entity(float width, float height) {
	mass = 1.5f;
	CalcMinMax(width, height);
	
}

Entity::Entity() {

}

void Entity::CalcMinMax(float width, float height) {
	float halfWidth = width * 0.5f;
	float halfHeight = height * 0.5f;

	maxWidth = halfWidth;
	minWidth = -halfWidth;

	maxHeight = halfHeight;
	minHeight = -halfHeight;

}
float Wrap(float coordinate, float min, float max){
	if (coordinate < min) return max;
	if (coordinate > max) return min;
	return coordinate;
}
void Entity::Update( float DT){
	position.x += velocity.x * DT;
	position.y += velocity.y * DT;
	
	position.x = Wrap(position.x, minWidth , maxWidth);
	position.y = Wrap(position.y, minHeight, maxHeight);

}
void Entity::DrawEntityPolygon() {
	glColor3f(1, 1, 1);
	
	glBegin(GL_POLYGON);
	for (int i = 0; i < pointsContainer.size(); i++) {
		glVertex2f(pointsContainer[i].x, pointsContainer[i].y);
	}
	glEnd();
}
void Entity::DrawEntity() {
	glColor3f(1, 1, 1);

	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < pointsContainer.size(); i++) {
		glVertex2f(pointsContainer[i].x, pointsContainer[i].y);
	}
	glEnd();
}

void Entity::Render() {
	glLoadIdentity();
	glTranslatef(position.x, position.y, 0.0f);

	DrawEntity();
}

void Entity::ApplyImpulse(Vector2 vec) {

}
void Entity::DrawHollowCircle() {

	int i;
	int lineAmount = 100; //# of triangles used to draw circle
	MathUtilities math;
	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * math.PI;
	glLoadIdentity();
	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= lineAmount; i++) {
		glVertex2f(
			position.x + (radius * cos(i *  twicePi / lineAmount)),
			position.y + (radius* sin(i * twicePi / lineAmount))
		);
	}
	glEnd();
	
}
void Entity::OnResize(float width, float height) {
	CalcMinMax(width,height);
}