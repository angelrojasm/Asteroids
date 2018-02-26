#pragma once
#ifndef _BULLET_H_
#define _BULLET_H_

#include "Entity.h"

class Bullet : public Entity
{


private:
	float TravelledDistance;
	bool IsActive;



public:

	Bullet();
	void ApplyImpulse(Vector2);
	void Update(float) override;
	void Render(void) override;
	bool getStatus(void);
	void SetStatus(bool);


};

#endif // !_BULLET_H_
