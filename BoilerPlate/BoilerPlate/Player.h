#pragma once
#include "Vector2.h"
#include "SDLEvent.hpp"
#include "Entity.h"
#include "Bullet.hpp"
class Player: public Entity
{

private:
	std::vector<Vector2> ThrusterContainer;
	bool IsThrusting;
	int PlayerLives;
	bool CanBeDestroyed;
	bool GameOver;


public:

	Player();
	~Player();

	
	void MoveForward(void);
	void RotateLeft	(void);
	void RotateRight(void); 
	void Update(float) override;
	void Render(void) override;
	bool getIsThrusting(void);
	void setIsThrusting(bool);
	Bullet* Shoot(void);
	int getPlayerLives(void);
	void LoseLives(int);
	void AddLives(int);
	void setRespawning(bool);
	bool getRespawningStatus(void);
	void setGameOver(bool);
	bool getGameOverStatus(void);
	void MoveTo(Vector2);

};

