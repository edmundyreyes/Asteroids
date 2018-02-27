#include "Game.hpp"

const int SHIP_PERSONAL_SPACE = 200;
const int FULLCIRCLE = 360;
const int TIME_MAX = 250;

Game::Game(){
	debuggTool = false;
	Framerates = std::vector <float>(300);
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
		if (KillBullet(Magazine[i])) Magazine[i].Update(DT);
	}
}
bool Game::KillBullet(Bullet casket) {
	if (casket.Getlife() < 0 && Magazine.size() > 0) {
		Magazine.erase(Magazine.begin());
		return false;
	}
	return true;
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
	if(debuggTool){
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
		if (debuggTool) Galaxy.pop_back();
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
		glColor3f(0.10,0.90,0.10);
		glVertex2f(object.position.x, object.position.y);
		glVertex2f(rock.position.x, rock.position.y);
		glEnd();
	}
}
void Game::BulletCollision() {
	
	if (!debuggTool) 
	{
		
		bool collision = false;
		for (int i = 0; i < Galaxy.size(); i++)
		{
			for (int j = 0; j < Magazine.size(); j++)
			{
				if (DetectColision(Galaxy[i], Magazine[j]))
				{
				
					if (Galaxy[i].Asteroid_GetSize() == Asteroids::BIG_SIZE) {
						Galaxy.push_back(Asteroids(Asteroids::MEDIUM_SIZE, Galaxy[i]));
						Galaxy.push_back(Asteroids(Asteroids::MEDIUM_SIZE, Galaxy[i]));
						Galaxy.erase(Galaxy.begin() + i);
						Magazine.erase(Magazine.begin() + j);
						collision = true;
						
					}
					else if (Galaxy[i].Asteroid_GetSize() == Asteroids::MEDIUM_SIZE) {
						Galaxy.push_back(Asteroids(Asteroids::SMALL_SIZE, Galaxy[i]));
						Galaxy.push_back(Asteroids(Asteroids::SMALL_SIZE, Galaxy[i]));
						Galaxy.erase(Galaxy.begin() + i);
						Magazine.erase(Magazine.begin() + j);
						collision = true;
					}
					else {
						Galaxy.erase(Galaxy.begin() + i);
						Magazine.erase(Magazine.begin() + j);
						collision = true;
					}
				}
				break;
			}
			if (collision) break;
		}
	}
}
void Game::ShipCollision(Player ship) {

	if (!debuggTool) {
		for (int i = 0; i < Galaxy.size(); i++)
		{
			if (DetectColision(ship, Galaxy[i])) {
				
				ship.ToggleLive();
				
			}
		}
	} 
}

void Game::Update(float DT) {

	UpdateGalaxy(DT);
	UpdateMagazine(DT);
	BulletCollision();
}
void Game::DebugMode(Player ship) {
	if (debuggTool) { 
		DrawAsteroidCircles();
		ship.DrawHollowCircle();
		DrawBulletCircle();
		for (int i = 0; i < Galaxy.size(); i++)
			RenderLines(ship,Galaxy[i]);
		Fps();
	}
}
void Game::Fps() {
	glLoadIdentity();
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 0.75, 0.25);
	for (int i = 0; i < TIME_MAX; i++)
		glVertex2f(i + 280, Framerates[i] - 1600);
	glEnd();
}
void Game::Render() {
	RenderGalaxy();
	RenderMagazine();
}