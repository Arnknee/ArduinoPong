#include "graphics.h"

#include <SDL.h>

Graphics::Graphics(int screenwidth, int screenheigth)
{
	_screenwidth = screenwidth;
	_screenheigth = screenheigth;

	SDL_CreateWindowAndRenderer(_screenwidth,_screenheigth , 0, &_window, &_renderer);
	SDL_SetWindowTitle(_window, "Game");
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
}

void Graphics::flip()
{
	SDL_RenderPresent(_renderer);
}

void Graphics::clear()
{
	SDL_RenderClear(_renderer);
}

SDL_Renderer* Graphics::getRenderer()
{
	return _renderer;
}

int Graphics::getScreenWidth()
{
	return _screenwidth;
}

int Graphics::getScreenHeigth()
{
	return _screenheigth;
}