#include "Entity.hpp"
/////// Constructors //////////////////////////////////////////////////////////////////////
Entity::Entity(){
	position = Vector2();
}

/////// others //////////////////////////////////////////////////////////////////////

void Entity::E_Update() {}

void Entity::E_DrawEntity() {
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < pointsContainer.size(); i++) {
		glVertex2f(pointsContainer[i].x, pointsContainer[i].y);
	}
	glEnd();
}
void Entity::E_Render() {
	glLoadIdentity();
	glTranslatef(position.x, position.y, 0.0f);

	E_DrawEntity();
}
/////// Functions for Motion //////////////////////////////////////////////////////////////////////

void Entity::E_Warping(int screenWidth, int screenHeight) {
	if (position.x < -screenWidth / 2)
		position.x += screenWidth;

	if (position.x > screenWidth / 2)
		position.x -= screenWidth;

	if (position.y < -screenHeight / 2)
		position.y += screenHeight;

	if (position.y > screenHeight / 2)
		position.y -= screenHeight;
}
