#pragma once
#include "Vector2.h"
#include "Entity.h"
class Asteroid: public Entity
{

	struct AsteroidSize {

		enum size {
			SMALL = 0,
			MEDIUM = 1,
			BIG = 2
		};
	};

private:
	AsteroidSize::size Size;

public:
	Asteroid();
	Asteroid(Asteroid::AsteroidSize::size);
	~Asteroid();


	void Update(void);
	void Render(void) override;
	AsteroidSize::size getSize(void);

};

