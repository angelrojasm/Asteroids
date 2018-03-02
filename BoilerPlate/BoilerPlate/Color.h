#pragma once
#include <GL/glew.h>
#include <SDL_opengl.h>
class Color
{
public:
	Color();
	Color(GLfloat value, GLfloat value2, GLfloat value3, GLfloat value4);
	~Color();
	GLfloat R;
	GLfloat G;
	GLfloat B;
	GLfloat A;
};

