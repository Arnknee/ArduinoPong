#ifndef PADDLE_H
#define PADDLE_H

#include "graphics.h"

class Paddle
{
public:
	SDL_Rect rect;

	Paddle(int screenwidth, int screenheigth, int paddleNumber);
	~Paddle();

	void render(Graphics &graphics, int r, int g, int b);
	void move(int screenwidth, int screenheigth, bool up);

	int getY();
	int getX();
	int getH();
	int getW();


	SDL_Rect getRect();

private:
	int _paddlewidth = 15;
	int _paddleheigth = 80;
	int _r, _g, _b;
};
#endif