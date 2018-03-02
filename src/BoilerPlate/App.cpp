#include "App.hpp"

namespace Engine
{
	const float DESIRED_FRAME_RATE = 60.0f;
	const float DESIRED_FRAME_TIME = 1.0f / DESIRED_FRAME_RATE;
	irrklang::ISoundEngine *SoundEngine = irrklang::createIrrKlangDevice();

	App::App(const std::string& title, const int width, const int height)
		: m_title(title)
		, m_width(width)
		, m_height(height)
		, m_nUpdates(0)
		, m_timer(new TimeManager)
		, m_mainWindow(nullptr)
	{
		m_playerONE  = new Player((float)(m_width), (float)(m_height));
		m_AntiAsteroidsBullet =  Bullet(*m_playerONE);

		m_Game = new Game((float)(m_width), (float)(m_height));
		m_Game->StartUpRoutine();

		m_InputManager = new InputManager();

		m_state = GameState::UNINITIALIZED;
		m_lastFrameTime = m_timer->GetElapsedTimeInSeconds();
	}

	App::~App()
	{
		CleanupSDL();
	}

	void App::Execute()
	{
		if (m_state != GameState::INIT_SUCCESSFUL)
		{
			std::cerr << "Game INIT was not successful." << std::endl;
			return;
		}

		m_state = GameState::RUNNING;

		SDL_Event event;
		while (m_state == GameState::RUNNING)
		{
			// Input polling
			//
			while (SDL_PollEvent(&event))
			{
				OnEvent(&event);
			}

			//
			Update();
			Render();
		}
	}

	bool App::Init()
	{
		// Init the external dependencies
		//
		bool success = SDLInit() && GlewInit();
		if (!success)
		{
			m_state = GameState::INIT_FAILED;
			return false;
		}

		// Setup the viewport
		//
		SetupViewport();

		// Change game state
		//
		m_state = GameState::INIT_SUCCESSFUL;

		return true;
	}

	void App::OnKeyDown(SDL_KeyboardEvent keyBoardEvent)
	{
		switch (keyBoardEvent.keysym.scancode)
		{
		case SDL_SCANCODE_ESCAPE:
			OnExit();
			break;
		
		// Move forward with "W" key or with "UP" key
		
		case SDL_SCANCODE_UP:
			m_InputManager->SetKeyUp(true);
			break;
		case SDL_SCANCODE_W:
			m_InputManager->SetKeyW(true);
			break;

		// ROTATE ship with "A" key or "LEFT" key

		case SDL_SCANCODE_LEFT:
			m_InputManager->SetKeyLeft(true);
			break;
		case SDL_SCANCODE_A:
			m_InputManager->SetKeyA(true);
			break;

		// ROTATE ship with "D" key or "RIGHT" key

		case SDL_SCANCODE_RIGHT:
			m_InputManager->SetKeyRight(true);
			break;
		case SDL_SCANCODE_D:
			m_InputManager->SetKeyD(true);
			break;

		// Creating asteroids with "U" key

		case SDL_SCANCODE_U:
			m_InputManager->SetKeyU(true);
			break;
		
		// deleting diferent asteroids with "j"
		
		case SDL_SCANCODE_J:
			m_InputManager->SetKeyJ(true);
			break;

		case SDL_SCANCODE_F:
			m_InputManager->SetKeyF(true);
			break;
		
		default:

			break;
		}
	}

	void App::OnKeyUp(SDL_KeyboardEvent keyBoardEvent)
	{
		switch (keyBoardEvent.keysym.scancode)
		{
		case SDL_SCANCODE_ESCAPE:
			m_playerONE->ToggleMove();
			OnExit();
			break;

		case SDL_SCANCODE_R:
			if(!m_Game->m_GAMEOVER) m_Game->m_GAMEOVER = true;
			break;

		case SDL_SCANCODE_W:
			m_InputManager->SetKeyW(false);
			m_playerONE->m_TrushterBool = false;
			break;

		case SDL_SCANCODE_A:
			m_InputManager->SetKeyA(false);
			break;

		case SDL_SCANCODE_D:
			m_InputManager->SetKeyD(false);
			break;

		case SDL_SCANCODE_UP:
			m_InputManager->SetKeyUp(false);
			m_playerONE->m_TrushterBool = false;
			break;

		case SDL_SCANCODE_LEFT:
			m_InputManager->SetKeyLeft(false);
			break;

		case SDL_SCANCODE_RIGHT:
			m_InputManager->SetKeyRight(false);
			
			break;

		case SDL_SCANCODE_SPACE:
			m_Game->ShootNewBullet(*m_playerONE);
			SoundEngine->play2D("audio/fire.wav");
			
			break;

		case SDL_SCANCODE_U:
			m_InputManager->SetKeyU( false);
			
			break;

		case SDL_SCANCODE_J:
			m_InputManager->SetKeyJ(false);
			
			break;

		case SDL_SCANCODE_P:
			m_Game->ToggleDebuggTool();
			
			break;

		case SDL_SCANCODE_F:
			m_InputManager->SetKeyF(false);
			break;

		default:
			//do nothing
			break;
		}
	}

	void App::Update()
	{
		double startTime = m_timer->GetElapsedTimeInSeconds();

		// Update code goes here
		InputManagement();
		//

		double endTime = m_timer->GetElapsedTimeInSeconds();
		double nextTimeFrame = startTime + DESIRED_FRAME_TIME;

		while (endTime < nextTimeFrame)
		{
			// Spin lock
			endTime = m_timer->GetElapsedTimeInSeconds();
		}

		double elapsedTime = endTime - startTime;

		m_Game->ShipCollision(*m_playerONE);
		m_Game->Update((float)(elapsedTime),*m_playerONE);
		m_playerONE->Update((float)(elapsedTime));


		m_lastFrameTime = m_timer->GetElapsedTimeInSeconds();

		m_nUpdates++;
	}

	void App::Render()
	{
		//            r      g    b		a
		glClearColor(0.10f, 0.15f, 0.40f, 1.0f);

		glClear(GL_COLOR_BUFFER_BIT);
		//if (m_playerONE.GetLives()) 
		m_playerONE->Render();
		m_Game->Render(*m_playerONE);
		m_Game->DebugMode(*m_playerONE);

		SDL_GL_SwapWindow(m_mainWindow);
	}

	bool App::SDLInit()
	{
		// Initialize SDL's Video subsystem

		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			std::cerr << "Failed to init SDL" << std::endl;
			return false;
		}
		
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

		Uint32 flags = SDL_WINDOW_OPENGL |
			SDL_WINDOW_SHOWN |
			SDL_WINDOW_RESIZABLE;

		m_mainWindow = SDL_CreateWindow(
			m_title.c_str(),
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			m_width,
			m_height,
			flags
		);

		if (!m_mainWindow)
		{
			std::cerr << "Failed to create window!" << std::endl;
			SDL_Quit();
			return false;
		}

		m_context = SDL_GL_CreateContext(m_mainWindow);
		SDL_GL_MakeCurrent(m_mainWindow, m_context);

		// Make double buffer interval synced with vertical scanline refresh
		SDL_GL_SetSwapInterval(0);

		return true;
	}

	void App::SetupViewport()
	{
		// Defining ortho values
		//
		float halfWidth = m_width * 0.5f;
		float halfHeight = m_height * 0.5f;

		// Set viewport to match window
		//
		glViewport(0, 0, m_width, m_height);

		// Set Mode to GL_PROJECTION
		//
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		// Set projection MATRIX to ORTHO
		//
		glOrtho(-halfWidth, halfWidth, -halfHeight, halfHeight, -1, 1);

		// Setting Mode to GL_MODELVIEW
		//
		glMatrixMode(GL_MODELVIEW);
	}

	bool App::GlewInit()
	{
		GLenum err = glewInit();
		if (GLEW_OK != err)
		{
			std::cerr << "Error: " << glewGetErrorString(err) << std::endl;
			return false;
		}

		return true;
	}

	void App::CleanupSDL()
	{
		// Cleanup
		//
		SDL_GL_DeleteContext(m_context);
		SDL_DestroyWindow(m_mainWindow);

		SDL_Quit();
	}

	void App::OnResize(int width, int height)
	{
		// TODO: Add resize functionality
		//
		m_width = width;
		m_height = height;

		SetupViewport();
		m_playerONE->OnResize((float)(m_width), (float)(m_height));
		m_Game->OnResize((float)(m_width), (float)(m_height));
	}

	void App::OnExit()
	{
		// Exit main for loop
		//
		m_state = GameState::QUIT;

		// Cleanup SDL pointers
		//
		CleanupSDL();
	}

	void App::InputManagement() {
		if (m_InputManager->GetKeyW()) {
			m_playerONE->MoveForward();
			SoundEngine->play2D("audio/thrust.wav");
		}
		if (m_InputManager->GetKeyA()) m_playerONE->RotateLeft();
		if (m_InputManager->GetKeyD()) m_playerONE->RotateRight();

		if (m_InputManager->GetKeyUp()) {
			m_playerONE->MoveForward();
			SoundEngine->play2D("audio/thrust.wav");
		} 
		if (m_InputManager->GetKeyRight())  m_playerONE->RotateRight();
		if (m_InputManager->GetKeyLeft()) m_playerONE->RotateLeft();

		if (m_InputManager->GetKeyU()) m_Game->CreateNewAsteroid();
		if (m_InputManager->GetKeyJ()) m_Game->DeleteAsteroid();
		if (m_InputManager->GetKeyP())
		if (m_InputManager->GetKeyF()) m_Game->Fps();
	}
}
