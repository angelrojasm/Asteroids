#pragma once
#include "Vector2.h"
#include "Entity.h"
#include "Bullet.h"
class Player: public Entity
{


private:

	bool IsThrusting;
	std::vector<Vector2> ThrusterContainer;
	float Friction;

	

public:

	Player();
	~Player();
	
	void Update(float) override;
	void Render(void) override;
	void RotateLeft	(void);
	void RotateRight(void); 
	bool getIsThrusting(void);
	void setIsThrusting(bool);
	Bullet Shoot(void);


};

