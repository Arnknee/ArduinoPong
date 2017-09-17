#include "paddle.h"

Paddle::Paddle(int screenwidth, int screenheigth,int paddlenumber)
{
	rect.h = _paddleheigth;
	rect.w = _paddlewidth;

	if (paddlenumber == 1)
	{
		rect.x = 0;
		rect.y = screenheigth / 2 - _paddleheigth / 2;
	}
	if (paddlenumber == 2)
	{
		rect.x = screenwidth - _paddlewidth;
		rect.y = screenheigth / 2 - _paddleheigth / 2;
	}
}

Paddle::~Paddle()
{

}

void Paddle::render(Graphics &graphics, int r, int g, int b)
{
	_r = r;
	_g = g;
	_b = b;
	SDL_SetRenderDrawColor(graphics.getRenderer(), _r, _g, _b, 255);
	
	SDL_RenderFillRect(graphics.getRenderer(), &rect);
}

void Paddle::move(int screenwidth, int screenheigth, bool up)
{
	int speed = 10;

	if (up)
	{
		if (rect.y - speed > 0)
			rect.y-= speed;
		else
			rect.y = 0;
	}
	if (!up)
	{
		if (rect.y + rect.h + speed < screenheigth)
			rect.y += speed;
		else
			rect.y = screenheigth - rect.h;
	}
}

SDL_Rect Paddle::getRect()
{
	return rect;
}

int Paddle::getY()
{
	return rect.y;
}

int Paddle::getX()
{
	return rect.x;
}

int Paddle::getH()
{
	return rect.h;
}

int Paddle::getW()
{
	return rect.w;
}