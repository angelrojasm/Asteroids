#include "Asteroid.h"
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>



Asteroid::Asteroid()
{
	PositionVector = Vector2();
	OrientationAngle = 0;
	mass = 0;
	Size = Asteroid::AsteroidSize::size::BIG;

	RenderingContainer.push_back(Vector2(0, -10));
	RenderingContainer.push_back(Vector2(-20, 20));
	RenderingContainer.push_back(Vector2(10, 50));
	RenderingContainer.push_back(Vector2(50, 50));
	RenderingContainer.push_back(Vector2(70, 20));
	RenderingContainer.push_back(Vector2(70, -10));
	RenderingContainer.push_back(Vector2(50, -30));
	RenderingContainer.push_back(Vector2(30, -30));
	RenderingContainer.push_back(Vector2(30, 0));
	RenderingContainer.push_back(Vector2(10, -30));
	RenderingContainer.push_back(Vector2(-20, 0));


}

Asteroid::Asteroid(Asteroid::AsteroidSize::size Asteroid_Size) {

	Size = Asteroid_Size;
}


Asteroid::~Asteroid()
{
}

Asteroid::AsteroidSize::size Asteroid::getSize() {

	return Size;

};

void::Asteroid::Update() {

}

void::Asteroid::Render() {

	glLoadIdentity();
	glTranslatef(PositionVector.X_coordinate, PositionVector.Y_coordinate, 0.0f);




	glBegin(GL_LINE_LOOP);

	switch (Size) {

	case Asteroid::AsteroidSize::size::SMALL:

		for (Vector2 Points : RenderingContainer) {
			glVertex2f(Points.X_coordinate / 3, Points.Y_coordinate / 3);
		}
		break;
	
	case Asteroid::AsteroidSize::size::MEDIUM:
		for (Vector2 Points : RenderingContainer) {
			glVertex2f(Points.X_coordinate / 2, Points.Y_coordinate / 2);
		}
		break;
	case Asteroid::AsteroidSize::size::BIG:
		for (Vector2 Points : RenderingContainer) {
			glVertex2f(Points.X_coordinate, Points.Y_coordinate);
		}
		break;
	default:
		break;

		 }
	
	glEnd();

}