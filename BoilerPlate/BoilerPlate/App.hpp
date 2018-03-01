#pragma once
#ifndef APP_HPP
#define APP_HPP

// C++ STL
#include <string>
#include <list>

// Asteroids
#include "TimeManager.hpp"
#include "Player.h"
#include "Asteroid.hpp"
#include "InputManager.h"

namespace Engine
{
	class App : public SDLEvent
	{
	public:
		/* =============================================================
		* ENUMERATORS
		* ============================================================= */
		struct GameState
		{
			enum State
			{
				UNINITIALIZED = 0,
				INIT_FAILED = 1,
				INIT_SUCCESSFUL = 2,
				RUNNING = 4,
				PAUSED = 8,
				QUIT = 16
			};
		};

		/* =============================================================
		 * PUBLIC FUNCTIONS
		 * ============================================================= */
		App( const std::string& title, const int width, const int height );
		~App( );
		void Execute						( );
		bool Init							( );
		void Update							( );
		void Render							( );
		void Asteroid_Creation				(int);
		void Asteroid_Deletion				(int);
		void CreateLineSegments				( );
		void PlayerCrash					( );
		void BulletCrash					( );
		void AsteroidSplitting				( );
		void UpdateFrames					( );
		void ShowFrames						( );

	private:
		/* =============================================================
		 * PRIVATE FUNCTIONS
		 * ============================================================= */
		bool SDLInit						( );
		bool GlewInit						( );
		void SetupViewport					( );
		void CleanupSDL						( );
		void OnResize						( int width, int height ) override;
		void OnExit							( ) override;
		void OnKeyDown						( SDL_KeyboardEvent keyBoardEvent ) override;
		void OnKeyUp						( SDL_KeyboardEvent keyBoardEvent ) override;
		void VerifyKeyInputs				( );


		/* =============================================================
		 * MEMBERS
		 * ============================================================= */
		int									m_width;
		int									m_height;
		int									m_nUpdates;
		double								m_lastFrameTime;
		std::string							m_title;
		SDL_Window*							m_mainWindow;
		SDL_GLContext						m_context;
		GameState::State					m_state;
		Engine::TimeManager*				m_timer;
		Player*								Ship;
		std::vector<Asteroid*>				AsteroidVector;
		std::vector<Entity*>				EntityVector;
		std::vector<Bullet*>				BulletVector;
		std::vector<Vector2>				Frames;
		int									FramePosition;
		bool								PlotIsVisible;
		InputManager						GameController;
		float								AsteroidKeyRegulator;
		float								BulletKeyRegulator;

		


	};
}
#endif /* GAME_HPP */
