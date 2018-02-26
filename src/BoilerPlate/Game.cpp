#include "Game.hpp"

const int SHIP_PERSONAL_SPACE = 200;
const int FULLCIRCLE = 360;
Game::Game(){
	deBuggtool = false;
}
void Game::RenderGalaxy() {
	for (int i = 0; i < Galaxy.size(); i++) {
		Galaxy[i].Render();
	}
}
void Game::RenderMagazine() {
	for (int i = 0; i < Magazine.size(); i++) {
		
		Magazine[i].Render();
	}
}
void Game::UpdateGalaxy(float DT) {
	for (int i = 0 ; i < Galaxy.size() ; i++) {
		Galaxy[i].Update(DT);
	}
}
void Game::UpdateMagazine(float DT) {
	for (int i = 0; i < Magazine.size(); i++) {
		Magazine[i].Update(DT);
	}
}
void Game::DrawAsteroidCircles() {
	for (int i = 0; i < Galaxy.size(); i++) {
		Galaxy[i].DrawHollowCircle();
	}
}
void Game::DrawBulletCircle() {
	for (int i = 0; i < Magazine.size(); i++) {
		Magazine[i].DrawHollowCircle();
	}
}
void Game::CreateNewAsteroid(float m_width,float m_height) {
	if(deBuggtool){
		Asteroids rock = Asteroids(m_width, m_height);
		rock.angle = rand() % FULLCIRCLE;
		rock.position = Vector2(rand(), rand());
		Galaxy.push_back(rock);
	}
}
void Game::ShootNewBullet(Player ship) {
	Bullet bulletCasket = Bullet(ship);
	Magazine.push_back(bulletCasket);
	
}
void Game::DeleteAsteroid() {
	if (Galaxy.size() > 0){
		if (deBuggtool) Galaxy.pop_back();
	}
}
float Game::CalculateDistance(Entity player, Entity asteroid) {
	//Ax is Asteroid axis x and Ay is asteroid axis y
	int Ax = asteroid.position.x;
	int Ay = asteroid.position.y;

	//Px is player axis x and Py is player axis y
	int Px = player.position.x;
	int Py = player.position.y;

	return sqrtf((Px - Ax)*(Px - Ax) + (Py - Ay)*(Py - Ay));
}
bool Game::DetectColision(Entity player, Entity asteroid) {
	if (CalculateDistance(player, asteroid) < player.radius + asteroid.radius)
		return true;
	else
		return false;

}
void Game::StartUpRoutine(float m_width,float m_height) {
	Asteroids rock = Asteroids(m_width, m_height);
	for (int i = 0; i < 4; i++) {
		rock.angle = rand() % FULLCIRCLE;
		rock.position = Vector2(rand(), rand());
		Galaxy.push_back(rock);
	}

}
void Game::RenderLines(Entity object, Entity rock) {
	
	if (SHIP_PERSONAL_SPACE >= CalculateDistance(object,rock)) {
		glBegin(GL_LINE_LOOP);
		//glColor3f(0.10,0.90,0.10);
		glVertex2f(object.position.x, object.position.y);
		glVertex2f(rock.position.x, rock.position.y);
		glEnd();
	}
}