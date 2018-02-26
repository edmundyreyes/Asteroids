#include "App.hpp"

namespace Engine
{
	const float DESIRED_FRAME_RATE = 60.0f;
	const float DESIRED_FRAME_TIME = 1.0f / DESIRED_FRAME_RATE;

	
	App::App(const std::string& title, const int width, const int height)
		: m_title(title)
		, m_width(width)
		, m_height(height)
		, m_nUpdates(0)
		, m_timer(new TimeManager)
		, m_mainWindow(nullptr)
	{
		playerONE  = Player(m_width, m_height);

		asteroidSmall = Asteroids(Asteroids::SMALL_SIZE, m_width, m_height);
		asteroidMid   = Asteroids(Asteroids::MEDIUM_SIZE, m_width, m_height);
		asteroidBig   = Asteroids(Asteroids::BIG_SIZE, m_width, m_height);

		gameUtility = Game();
		gameUtility.StartUpRoutine(asteroidBig);

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
			playerONE.MoveForward();
			SDL_Log("UP was pressed.", keyBoardEvent.keysym.scancode);
			break;
		case SDL_SCANCODE_W:
			playerONE.MoveForward();
			SDL_Log("W was pressed.", keyBoardEvent.keysym.scancode);
			break;

		// ROTATE ship with "A" key or "LEFT" key

		case SDL_SCANCODE_LEFT:
			playerONE.RotateLeft();
			SDL_Log("LEFT was pressed.", keyBoardEvent.keysym.scancode);
			break;
		case SDL_SCANCODE_A:
			playerONE.RotateLeft();
			SDL_Log("A was pressed.", keyBoardEvent.keysym.scancode);
			break;

		// ROTATE ship with "D" key or "RIGHT" key

		case SDL_SCANCODE_RIGHT:
			playerONE.RotateRight();
			SDL_Log("RIGHT was pressed.", keyBoardEvent.keysym.scancode);
			break;
		case SDL_SCANCODE_D:
			playerONE.RotateRight();
			SDL_Log("D was pressed.", keyBoardEvent.keysym.scancode);
			break;

		// Creating diferent asteroids with "U, I, O" keys

		case SDL_SCANCODE_U:
			gameUtility.CreateNewAsteroid(asteroidSmall);
			cout << "Render a small Asteroid" << endl;
			break;
		case SDL_SCANCODE_I:
			gameUtility.CreateNewAsteroid(asteroidMid);
			cout << "Render a midium Asteroid" << endl;
			break;
		case SDL_SCANCODE_O:
			gameUtility.CreateNewAsteroid(asteroidBig);
			cout << "Render a big Asteroid" << endl;
			break;

		// deleting diferent asteroids with "j"
		
		case SDL_SCANCODE_J:
			gameUtility.DeleteAsteroid();
			cout << "erase a Asteroid" << endl;
			break;
		
		default:
			SDL_Log("%S was pressed.", keyBoardEvent.keysym.scancode);
			break;
		}
	}

	void App::OnKeyUp(SDL_KeyboardEvent keyBoardEvent)
	{
		switch (keyBoardEvent.keysym.scancode)
		{
		case SDL_SCANCODE_ESCAPE:
			playerONE.ToggleMove();
			OnExit();
			break;

		case SDL_SCANCODE_UP:
			playerONE.trushterBool = false;
			break;

		case SDL_SCANCODE_P:
			gameUtility.ToggleDebuggTool();
			
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
		playerONE.Update( DESIRED_FRAME_TIME);
		gameUtility.UpdateGalaxy(DESIRED_FRAME_TIME);

		//

		double endTime = m_timer->GetElapsedTimeInSeconds();
		double nextTimeFrame = startTime + DESIRED_FRAME_TIME;

		while (endTime < nextTimeFrame)
		{
			// Spin lock
			endTime = m_timer->GetElapsedTimeInSeconds();
		}

		//double elapsedTime = endTime - startTime;        

		m_lastFrameTime = m_timer->GetElapsedTimeInSeconds();

		m_nUpdates++;
	}

	void App::Render()
	{
		//            r      g    b		a
		glClearColor(0.10, 0.15f, 0.40f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		playerONE.Render();
		gameUtility.RenderGalaxy();
		
		if (gameUtility.deBuggtool) { //if the debug tool is on.
			playerONE.DrawHollowCircle();
			gameUtility.DrawAsteroidCircles();
			for (int i = 0; i < gameUtility.Galaxy.size(); i++)
				gameUtility.RenderLines(playerONE, gameUtility.Galaxy[i]);

		}

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
}
