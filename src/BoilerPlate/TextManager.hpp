#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_ttf.h>

class TextManager
{

public:
	TextManager();
	TextManager(TTF_Font*, SDL_Color);
	void TextManagerInit();
	void RenderText(std::string message, SDL_Color color, float x, float y, int size);
	unsigned int power_two_floor(unsigned int);


private:

	TTF_Font * font;
	SDL_Color color;

};

