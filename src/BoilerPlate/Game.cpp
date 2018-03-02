#include "Game.hpp"

const int SHIP_PERSONAL_SPACE = 200;
const int FULLCIRCLE = 360;
const int TIME_MAX = 250;
const int FONT_SIZE = 50;
int currentIndex = 0;

irrklang::ISoundEngine *SoundEngine = irrklang::createIrrKlangDevice();
Game::Game(float width, float height){
	m_debuggTool = false;
	m_Framerates = std::vector <float>(300); 
	m_score = 0;
	m_width = width; 
	m_height = height;
	m_textRenderer.TextManagerInit();
	InitGameFontColor(255, 255, 255, 255);
	m_GameFont = TTF_OpenFont("Fonts/font.ttf", FONT_SIZE);

	if (m_GameFont == NULL) system("PAUSE");
	m_textRenderer = TextManager(m_GameFont, m_GameFontColor);
}
void Game::RenderGalaxy() {
	for (int i = 0; i < m_Galaxy.size(); i++) {
		m_Galaxy[i].Render();
	}
}
void Game::RenderMagazine() {
	for (int i = 0; i < m_Magazine.size(); i++) {
		m_Magazine[i].Render();
	}
}
void Game::UpdateGalaxy(float DT) {
	if (m_Galaxy.size() < 2) m_Galaxy.push_back(Asteroids(1116,360));
	for (int i = 0 ; i < m_Galaxy.size() ; i++) {
		m_Galaxy[i].Update(DT);
	}
}
void Game::UpdateMagazine(float DT) {
	for (int i = 0; i < m_Magazine.size(); i++) {
		if (KillBullet(m_Magazine[i])) m_Magazine[i].Update(DT);
	}
}
bool Game::KillBullet(Bullet casket) {
	if (casket.Getlife() < 0 && m_Magazine.size() > 0) {
		m_Magazine.erase(m_Magazine.begin());
		return false;
	}
	return true;
}
void Game::DrawAsteroidCircles() {
	for (int i = 0; i < m_Galaxy.size(); i++) {
		m_Galaxy[i].DrawHollowCircle();
	}
}
void Game::DrawBulletCircle() {
	for (int i = 0; i < m_Magazine.size(); i++) {
		m_Magazine[i].DrawHollowCircle();
	}
}
void Game::CreateNewAsteroid(float m_width,float m_height) {
	if(m_debuggTool){
		Asteroids rock = Asteroids(m_width, m_height);
		rock.angle = rand() % FULLCIRCLE;
		rock.position = Vector2(rand(), rand());
		m_Galaxy.push_back(rock);
	}
}
void Game::ShootNewBullet(Player ship) {
	Bullet bulletCasket = Bullet(ship);
	if(ship.GetLive())m_Magazine.push_back(bulletCasket);
}
void Game::DeleteAsteroid() {
	if (m_Galaxy.size() > 0){
		if (m_debuggTool) m_Galaxy.pop_back();
	}
}
float Game::CalculateDistance(Entity player, Entity asteroid) {
	
	//Ax is Asteroid axis x and Ay is asteroid axis y
	float Ax = asteroid.position.x;
	float Ay = asteroid.position.y;

	//Px is player axis x and Py is player axis y
	float Px = player.position.x;
	float Py = player.position.y;
	
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
		m_Galaxy.push_back(rock);
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
	
	if (!m_debuggTool) 
	{

		vector <Asteroids> currentAsteroids;
		for (int i = 0; i < m_Galaxy.size(); i++)
		{
			if (CheckCollisionWithMagazine(m_Galaxy[i])) {
				if (m_Galaxy[i].Asteroid_GetSize() == Asteroids::BIG_SIZE) {
					currentAsteroids.push_back(Asteroids(Asteroids::MEDIUM_SIZE, m_Galaxy[i]));
					currentAsteroids.push_back(Asteroids(Asteroids::MEDIUM_SIZE, m_Galaxy[i]));
					SoundEngine->play2D("audio/bangLarge.wav");
					m_score += 20;
				}
				else if (m_Galaxy[i].Asteroid_GetSize() == Asteroids::MEDIUM_SIZE) {
					currentAsteroids.push_back(Asteroids(Asteroids::SMALL_SIZE, m_Galaxy[i]));
					currentAsteroids.push_back(Asteroids(Asteroids::SMALL_SIZE, m_Galaxy[i]));
					SoundEngine->play2D("audio/bangMedium.wav");
					m_score += 50;
				}
				else SoundEngine->play2D("audio/bangSmall.wav");
				m_score += 100;
			}
			else {
				currentAsteroids.push_back(m_Galaxy[i]);
			}
		}
		m_Galaxy = currentAsteroids;
	}
}
bool Game::CheckCollisionWithMagazine(Asteroids temp)
{
	vector <Bullet> currentBullets;
	bool collision = false;
	for (int i = 0; i < m_Magazine.size(); i++)
	{
		if (DetectColision(temp, m_Magazine[i])) collision = true;
		else currentBullets.push_back(m_Magazine[i]);
	}
	m_Magazine = currentBullets;
	return collision;
}

void Game::ShipCollision(Player &ship) {
	if (!m_debuggTool) {
		for (int i = 0; i < m_Galaxy.size(); i++)
		{
			if(ship.GetLive() == true){
				if (DetectColision(ship, m_Galaxy[i])) {
					ship.Killit();
				}
			}
		}
	} 
}
void Game::Update(float DT, Player &ship) {
	m_Framerates[currentIndex++] = DT*5000;
	if (currentIndex == TIME_MAX) currentIndex = 0;
	UpdateGalaxy(DT);
	UpdateMagazine(DT);
	ShipCollision(ship);
	BulletCollision();
}

void Game::DebugMode(Player ship) {
	if (m_debuggTool) { 
		DrawAsteroidCircles();
		ship.DrawHollowCircle();
		DrawBulletCircle();
		for (int i = 0; i < m_Galaxy.size(); i++)
			RenderLines(ship,m_Galaxy[i]);
	}
}

void Game::Fps() {
	glLoadIdentity();
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 0.75, 0.25);
		for (int i = 0; i < TIME_MAX; i++) {
			glVertex2f(i + 280, m_Framerates[i] - 300);
		}
	glEnd();
}
void Game::Render(Player ship) {
	RenderGalaxy();
	RenderMagazine();
	RenderGameGUI(ship);
}
void Game::InitGameFontColor(int R, int G, int B, int A){
	m_GameFontColor.r = R;
	m_GameFontColor.g = G;
	m_GameFontColor.b = B;
	m_GameFontColor.a = A;
}
void Game::RenderGameGUI(Player ship){
	m_textRenderer.RenderText("SCORE  " + std::to_string(m_score), 
		m_GameFontColor, (m_width / 2.0f) - 340.0f, (m_height / 2.0f) - 60.0f, FONT_SIZE);

	if (ship.GetStocks() == 0 && !ship.GetLive()){
		m_textRenderer.RenderText("GAME OVER", m_GameFontColor, -50.0f, 0.0f, FONT_SIZE);
		//m_textRenderer.RenderText("PRESS R TO PLAY AGAIN", m_GameFontColor, -400.0f, -100.0f, FONT_SIZE);
	}

	if (!ship.GetLive() && ship.GetStocks() != 0){
		m_textRenderer.RenderText("RESPAWNING", m_GameFontColor, -50.0f, 0.0f, FONT_SIZE);
	}

}
