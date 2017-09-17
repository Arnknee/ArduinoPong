#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>


class Graphics
{
public:

	Graphics(int screenwidth, int screenheigth);
	~Graphics();

	void flip();
	void clear();

	SDL_Renderer * getRenderer();
	int getScreenHeigth();
	int getScreenWidth();
private:
	SDL_Window* _window = NULL;
	SDL_Renderer* _renderer = NULL;
	int _screenwidth, _screenheigth;
};
#endif