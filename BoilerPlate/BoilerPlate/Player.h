#pragma once
#include "Vector2.h"
#include "SDLEvent.hpp"
#include "Entity.h"
#include "Bullet.hpp"
class Player: public Entity
{



public:

	std::vector<Vector2> ThrusterContainer;
	float Friction;
	bool IsThrusting;
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


};

