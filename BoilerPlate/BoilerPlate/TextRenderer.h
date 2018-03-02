#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_ttf.h>

class TextRenderer
{

public:
	TextRenderer();
	TextRenderer(TTF_Font*, SDL_Color);
	void TextRenderInit();
	void RenderText(std::string message, SDL_Color color, float x, float y, int size);
	unsigned int power_two_floor(unsigned int);


private:

	TTF_Font * Font;
	SDL_Color Color;

};