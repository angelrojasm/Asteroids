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

private:
	AsteroidSize::size Size;


};

