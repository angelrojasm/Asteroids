#pragma once
#include "Vector2.h"
#include "Entity.h"
class Player: public Entity
{


private:

	bool IsThrusting;
	std::vector<Vector2> ThrusterContainer;
	

public:

	Player();
	~Player();
					
	void Render(void) override;
	void MoveForward(void);
	void RotateLeft	(void);
	void RotateRight(void); 
	bool getIsThrusting(void);
	void setIsThrusting(bool);


};

