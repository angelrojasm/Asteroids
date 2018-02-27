#include "App.hpp"
#include <iostream>
#include <algorithm>
#include "Paint.h"
#include "Player.h"
#include <ctime>

// OpenGL includes
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

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
		m_state = GameState::UNINITIALIZED;
		m_lastFrameTime = m_timer->GetElapsedTimeInSeconds();
		Ship = new Player();
		EntityVector.push_back(Ship);
		Asteroid_Creation(5);
		
	}

	App::~App()
	{
		CleanupSDL();
	}

	void App::Asteroid_Creation(int Asteroid_Quantity) {
		srand(time(NULL));

		for (int i = 0; i < Asteroid_Quantity; i++) {
			float Asteroid_X_Position = rand() % 1136;
			if (Asteroid_X_Position > 568) {
				Asteroid_X_Position -= 568;
				Asteroid_X_Position *= -1;
			}
			float Asteroid_Y_Position = rand() % 640;
			if (Asteroid_Y_Position > 320) {
				Asteroid_Y_Position -= 320;
				Asteroid_Y_Position *= -1;
			}
			float Asteroid_Orientation_Angle = rand() % 361;
			int Asteroid_Size = rand() % 3;

			Asteroid* newAsteroid = new Asteroid((Asteroid::AsteroidSize::size)Asteroid_Size, Asteroid_Orientation_Angle, Asteroid_X_Position, Asteroid_Y_Position);

			AsteroidVector.push_back(newAsteroid);
			EntityVector.push_back(newAsteroid);
		

		}

	}

	void App::Asteroid_Deletion(int Asteroid_Quantity) {
		if (AsteroidVector.size() > 0) {
			for (int i = 0;i < Asteroid_Quantity;i++) {
				AsteroidVector.pop_back();
				EntityVector.pop_back();
			}
		}
	}

	void App::CreateLineSegments()
	{
		if (Ship->getDebugging() && !Ship->HasCollided())
		{
			Vector2 ShipSpace = Ship->getPositionVector();
			Vector2 AsteroidPosition;
			float	AreaMeasurement = Ship->getRadius() * 2;
			float AsteroidRadius;
			float Distance;
			float DistanceToCircle;

			glLoadIdentity();
			glBegin(GL_LINE_LOOP);
			for (int i = 0; i < AsteroidVector.size(); i++)
			{
				AsteroidPosition = (*AsteroidVector[i]).getPositionVector();
				AsteroidRadius = (*AsteroidVector[i]).getRadius();
				Distance = Ship->EntityDistance((*AsteroidVector[i]));


				DistanceToCircle = AreaMeasurement + AsteroidRadius;

				if (Distance <= DistanceToCircle)
				{
					glColor3f(1.0, 0.0, 0.0);
					glVertex2f(ShipSpace.X_coordinate, ShipSpace.Y_coordinate);
					glVertex2f(AsteroidPosition.X_coordinate, AsteroidPosition.Y_coordinate);
				}


				glColor3f(1.0, 1.0, 1.0);
			}
			glEnd();
		}
	}

	void App::PlayerCrash()
	{
		for (int i = 0; i < AsteroidVector.size(); i++)
		{
			if (!Ship->HasCollided() && !(*AsteroidVector[i]).HasCollided())
			{
				Ship->DetectCollision(*AsteroidVector[i]);
			}
		}
	}

	/*void App::OnBulletCollision(void)
	{
		for (int i = 0; i < m_asteroids.size(); i++)
		{
			for (int j = 0; j < m_bullets.size(); j++)
			{
				if (m_asteroids[i]->DetectCollision(*m_bullets[j]))
				{
					//When bullets collide with asteroids they should split them in smaller halves
					if (m_asteroids[i]->GetSize() == Asteroid::Size::BIG)
					{
						Vector2 originalPosition = m_asteroids[i]->GetPosition();
						float originalOrientaion = m_asteroids[i]->GetOrientation();

						Asteroid* firstChild = new Asteroid(Asteroid::Size::MEDIUM, originalPosition.x,
							originalPosition.y, originalOrientaion);

						Asteroid* secondChild = new Asteroid(Asteroid::Size::MEDIUM, originalPosition.x,
							originalPosition.y, originalOrientaion + ROTATING_SPEED);

						m_asteroids.push_back(firstChild);
						m_entities.push_back(firstChild);

						m_asteroids.push_back(secondChild);
						m_entities.push_back(secondChild);

						m_bullets[j]->SetDisappearanceStatus(true);
						m_bullets.erase(m_bullets.begin() + j); //Delete bullet
						m_asteroids.erase(m_asteroids.begin() + i); //Delete parent Asteroid
					}

					else if (m_asteroids[i]->GetSize() == Asteroid::Size::MEDIUM)
					{
						Vector2 originalPosition = m_asteroids[i]->GetPosition();
						float originalOrientaion = m_asteroids[i]->GetOrientation();

						Asteroid* firstChild = new Asteroid(Asteroid::Size::SMALL, originalPosition.x,
							originalPosition.y, originalOrientaion);

						Asteroid* secondChild = new Asteroid(Asteroid::Size::SMALL, originalPosition.x,
							originalPosition.y, originalOrientaion + ROTATING_SPEED);

						m_asteroids.push_back(firstChild);
						m_entities.push_back(firstChild);

						m_asteroids.push_back(secondChild);
						m_entities.push_back(secondChild);

						m_bullets[j]->SetDisappearanceStatus(true);
						m_bullets.erase(m_bullets.begin() + j); //Delete bullet
						m_asteroids.erase(m_asteroids.begin() + i); //Delete parent Asteroid
					}

					else if (m_asteroids[i]->GetSize() == Asteroid::Size::SMALL)
					{
						m_bullets[j]->SetDisappearanceStatus(true);
						m_bullets.erase(m_bullets.begin() + j); //Delete bullet
						m_asteroids.erase(m_asteroids.begin() + i); //Delete parent Asteroid
					}

					break; //Stop evaluating after a collision is detected
				}
				else
				{
					if (m_bullets[j]->GetDisappearanceStatus())
						m_bullets.erase(m_bullets.begin() + j); //Delete bullet that has disappeared and not collided
				}
			}
		}
	}*/
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
		switch (keyBoardEvent.keysym.scancode) {

		case SDL_SCANCODE_UP:
			Ship->MoveForward();
			Ship->setIsThrusting(true);
			break;

		case SDL_SCANCODE_LEFT:
			Ship->RotateLeft();
			break;

		case SDL_SCANCODE_RIGHT:

			Ship->RotateRight();
			break;
		case SDL_SCANCODE_P:
			Asteroid_Creation(1);
			break;
		case SDL_SCANCODE_O:
			Asteroid_Deletion(1);
			break;
		case SDL_SCANCODE_D:
			for (int i = 0;i < EntityVector.size();i++) {
				EntityVector[i]->setDebugging(true);
			}
			break;
		case SDL_SCANCODE_SPACE: {
			Bullet* currentBullet = Ship->Shoot();
			BulletVector.push_back(currentBullet);
			EntityVector.push_back(currentBullet);
			break;
		}
		default:
			SDL_Log("%S was pressed.", keyBoardEvent.keysym.scancode);
			break;
		}
	}

	void App::OnKeyUp(SDL_KeyboardEvent keyBoardEvent)
	{
		Ship->setIsThrusting(false);
		switch (keyBoardEvent.keysym.scancode)
		{
		case SDL_SCANCODE_ESCAPE:
			OnExit();
			break;
		case SDL_SCANCODE_D:
			for (int i = 0;i < EntityVector.size();i++) {
				EntityVector[i]->setDebugging(false);
			}

		default:
			//DO NOTHING
			break;
		}
	}

	void App::Update()
	{
	
		

		double startTime = m_timer->GetElapsedTimeInSeconds();

		// Update code goes here
		//
		//Ship->Update(DESIRED_FRAME_TIME);
		for (int i = 0;i <= AsteroidVector.size();i++) {
			EntityVector[i]->Update(DESIRED_FRAME_TIME);
		}

		PlayerCrash();
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
		Paint x;
	
		glClearColor(0,0,0,1);
		glClear(GL_COLOR_BUFFER_BIT);
		//Ship->Render();
		
		for (int i = 0;i <= AsteroidVector.size();i++) {
			EntityVector[i]->Render();
		}

		for (int i = 0;i < BulletVector.size();i++) {
			BulletVector[i]->Render();
		}

		CreateLineSegments();
		SDL_GL_SwapWindow(m_mainWindow);
	}

	bool App::SDLInit()
	{
		// Initialize SDL's Video subsystem
		//
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			std::cerr << "Failed to init SDL" << std::endl;
			return false;
		}

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

		Uint32 flags =  SDL_WINDOW_OPENGL     | 
						SDL_WINDOW_SHOWN      | 
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
