#pragma once
#include "Entity.h"
#include "Vector2.h"
#include <vector>
class Asteroid : public Entity
{
public:
	struct AsteroidSize {

		enum size {
			SMALL = 0,
			MEDIUM = 1,
			BIG = 2
		};
	};
	Asteroid();
	Asteroid(Asteroid::AsteroidSize::size, float, float, float);
	~Asteroid();

	void Update(float) override;
	void Render(void) override;
	AsteroidSize::size getSize(void);
	void ApplyImpulse(Vector2);

	const float Asteroid_Moving_Speed = 60.0f;
	const float Asteroid_Rotating_Speed = 40.0f;
	const float Size_Inverse_Scale_Small = 0.3333f;
	const float Size_Inverse_Scale_Medium = 0.5f;
	const float Asteroid_Base_Size = 60.0f;

private:
	AsteroidSize::size Size;


};

