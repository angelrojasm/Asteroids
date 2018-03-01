#include "App.hpp"
#include <iostream>
#include <algorithm>
#include "Paint.h"
#include "Player.h"
#include <ctime>

// OpenGL includes
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>


bool test;

namespace Engine
{
	const float XPosition = 400.0f;
	const float YPosition = -300.0f;
	const int MaxFrames = 10;
	const float XScale = 10.0f;
	const float YScale = 100000.0f;
	const float DESIRED_FRAME_RATE = 60.0f;
	const float DESIRED_FRAME_TIME = 1.0f / DESIRED_FRAME_RATE;
	float deltaTime;

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
		PlotIsVisible = false;
		deltaTime = DESIRED_FRAME_TIME;
		FramePosition = 0;
		AsteroidKeyRegulator = 60;
		BulletKeyRegulator = 15;
		Frames = std::vector<Vector2>(MaxFrames);

		for (int i = 0; i < Frames.size(); i++)
		{
			Frames[i] = Vector2(i, DESIRED_FRAME_TIME);
		}
	}

	App::~App()
	{
		CleanupSDL();
	}

	void RenderText(std::string message, SDL_Color color, float x, float y, int size) {
		//Create Font Class
		//Create RenderingManager Class
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

			Asteroid* newAsteroid = new Asteroid(Asteroid::AsteroidSize::size::BIG, Asteroid_Orientation_Angle, Asteroid_X_Position, Asteroid_Y_Position);

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

	void App::AsteroidSplitting(void)
	{
		
		for (int FirstCounter = 0; FirstCounter < AsteroidVector.size(); FirstCounter++)
		{
			for (int SecondCounter = 0; SecondCounter < BulletVector.size(); SecondCounter++)
			{
				bool ok = AsteroidVector[FirstCounter]->DetectCollision(*BulletVector[SecondCounter]);
 				if (ok)
				{
					test = AsteroidVector[FirstCounter]->DetectCollision(*BulletVector[SecondCounter]);
					if (AsteroidVector[FirstCounter]->getSize() == Asteroid::AsteroidSize::BIG)
					{
						Vector2 Position = AsteroidVector[FirstCounter]->getPositionVector();
						float OrientationAngle = AsteroidVector[FirstCounter]->getOrientationAngle();

						Asteroid* FirstSplit = new Asteroid(Asteroid::AsteroidSize::MEDIUM, OrientationAngle,
							Position.X_coordinate, Position.Y_coordinate);

						Asteroid* SecondSplit = new Asteroid(Asteroid::AsteroidSize::MEDIUM, OrientationAngle + 30.0f,
							Position.X_coordinate,Position.Y_coordinate);

						AsteroidVector.push_back(FirstSplit);
						EntityVector.push_back(FirstSplit);

						AsteroidVector.push_back(SecondSplit);
						EntityVector.push_back(SecondSplit);

						BulletVector[SecondCounter]->SetStatus(false);
						BulletVector.erase(BulletVector.begin() + SecondCounter); 
						AsteroidVector.erase(AsteroidVector.begin() + FirstCounter); 
					}

					else if (AsteroidVector[FirstCounter]->getSize() == Asteroid::AsteroidSize::MEDIUM)
					{
						Vector2 Position = AsteroidVector[FirstCounter]->getPositionVector();
						float OrientationAngle = AsteroidVector[FirstCounter]->getOrientationAngle();

						Asteroid* FirstSplit = new Asteroid(Asteroid::AsteroidSize::SMALL, OrientationAngle,
							Position.X_coordinate, Position.Y_coordinate);

						Asteroid* SecondSplit = new Asteroid(Asteroid::AsteroidSize::SMALL, OrientationAngle + 30.0f,
							Position.X_coordinate, Position.Y_coordinate);

						AsteroidVector.push_back(FirstSplit);
						EntityVector.push_back(FirstSplit);

						AsteroidVector.push_back(SecondSplit);
						EntityVector.push_back(SecondSplit);

						BulletVector[SecondCounter]->SetStatus(false);
						BulletVector.erase(BulletVector.begin() + SecondCounter); 
						AsteroidVector.erase(AsteroidVector.begin() + FirstCounter);
					}

					else if (AsteroidVector[FirstCounter]->getSize() == Asteroid::AsteroidSize::SMALL)
					{
						BulletVector[SecondCounter]->SetStatus(false);
						BulletVector.erase(BulletVector.begin() + SecondCounter); 
						AsteroidVector.erase(AsteroidVector.begin() + FirstCounter);
					}

					break; 
				}
				else
				{
					if (!BulletVector[SecondCounter]->getStatus())
						BulletVector.erase(BulletVector.begin() + SecondCounter);
				}
			}
		}
	}

	void App::VerifyKeyInputs() {
		if (!GameController.getkey_Up_was_pressed()) {
			Ship->setIsThrusting(false);
		}
		if (!GameController.getkey_F_was_pressed()) {
			PlotIsVisible = false;
		}

		if (!GameController.getkey_D_was_pressed()) {
			for (int i = 0;i < EntityVector.size();i++) {
				EntityVector[i]->setDebugging(false);
			}
		}

		if (GameController.getkey_Up_was_pressed()) {

			Ship->MoveForward();
			Ship->setIsThrusting(true);
		}


		if (GameController.getkey_Left_was_pressed()) {

			Ship->RotateLeft();
		}

		if (GameController.getkey_Right_was_pressed()) {
			Ship->RotateRight();
		}

		if (GameController.getkey_P_was_pressed() && AsteroidKeyRegulator == 0) {
			AsteroidKeyRegulator = 60;
			Asteroid_Creation(1);
		}

		if (GameController.getkey_O_was_pressed() && AsteroidKeyRegulator == 0) {
			AsteroidKeyRegulator = 60;
			Asteroid_Deletion(1);
		}

		if (GameController.getkey_D_was_pressed()) {
			for (int i = 0;i < EntityVector.size();i++) {
				EntityVector[i]->setDebugging(true);
			}
		}

		if (GameController.getkey_F_was_pressed()) {
			PlotIsVisible = true;
		}

		if (GameController.getkey_Space_was_pressed() && BulletKeyRegulator == 0) {
			BulletKeyRegulator = 15;
			Bullet* currentBullet = Ship->Shoot();
			BulletVector.push_back(currentBullet);
			EntityVector.push_back(currentBullet);
		}

	}
	void App::UpdateFrames(void)
	{
		Frames[FramePosition] = Vector2((float)FramePosition, deltaTime);
		FramePosition++;

		if (FramePosition >= MaxFrames)
			FramePosition = 0;
	}

	void App::ShowFrames(void)
	{
		glColor4f(1.0f,1.0f, 1.0f, 1.0f);
		glLoadIdentity();
		//Locate in window
		glTranslatef(XPosition, YPosition, 0.0f);
		glBegin(GL_LINE_STRIP);
		glVertex2f(0.0f, 100.0f); 
		glVertex2f(0.0f, 0.0f); 
		glVertex2f(130.0f, 0.0f); 
		glEnd();

		glBegin(GL_LINE_STRIP);
		
		for (int i = 0; i <MaxFrames; i++)
		{
			glVertex2f(XScale * Frames[i].X_coordinate, YScale * (DESIRED_FRAME_TIME -Frames[i].Y_coordinate));
		}
		glEnd();
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
		switch (keyBoardEvent.keysym.scancode) {

		case SDL_SCANCODE_UP:
			GameController.setkey_Up_was_pressed(true);
			break;

		case SDL_SCANCODE_LEFT:
			GameController.setkey_Left_was_pressed(true);
			break;

		case SDL_SCANCODE_RIGHT:
			GameController.setkey_Right_was_pressed(true);
			break;
		case SDL_SCANCODE_P:
			GameController.setkey_P_was_pressed(true);
			break;
		case SDL_SCANCODE_O:
			GameController.setkey_O_was_pressed(true);
			break;
		case SDL_SCANCODE_D:
			GameController.setkey_D_was_pressed(true);
			break;
		case SDL_SCANCODE_F:
			GameController.setkey_F_was_pressed(true);
			break;
		case SDL_SCANCODE_SPACE: {
			GameController.setkey_Space_was_pressed(true);
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
		case SDL_SCANCODE_UP:
			GameController.setkey_Up_was_pressed(false);
			break;

		case SDL_SCANCODE_LEFT:
			GameController.setkey_Left_was_pressed(false);
			break;

		case SDL_SCANCODE_RIGHT:
			GameController.setkey_Right_was_pressed(false);
			break;
		case SDL_SCANCODE_P:
			GameController.setkey_P_was_pressed(false);
			break;
		case SDL_SCANCODE_O:
			GameController.setkey_O_was_pressed(false);
			break;
		case SDL_SCANCODE_D:
			GameController.setkey_D_was_pressed(false);
			break;
		case SDL_SCANCODE_F:
			GameController.setkey_F_was_pressed(false);
			break;
		case SDL_SCANCODE_SPACE: {
			GameController.setkey_Space_was_pressed(false);
			break;
		}
		default:
			//DO NOTHING
			break;
		}
	}

	void App::Update()
	{
		VerifyKeyInputs();
		if (AsteroidKeyRegulator >= 1) {
			AsteroidKeyRegulator--;
		}
		if (BulletKeyRegulator >= 1) {
			BulletKeyRegulator--;
		}

		double startTime = m_timer->GetElapsedTimeInSeconds();

		// Update code goes here
		//
		
		AsteroidSplitting();
		PlayerCrash();



		for (int i = 0; i < EntityVector.size();i++) {
			EntityVector[i]->Update(DESIRED_FRAME_TIME);
		}


		double endTime = m_timer->GetElapsedTimeInSeconds();
		double nextTimeFrame = startTime + DESIRED_FRAME_TIME;

		deltaTime = DESIRED_FRAME_TIME - (endTime - startTime);
		UpdateFrames();

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
	
		
		for (int i = 0;i < EntityVector.size();i++) {
			EntityVector[i]->Render();
		}

		CreateLineSegments();

		if (PlotIsVisible)
			ShowFrames();
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
