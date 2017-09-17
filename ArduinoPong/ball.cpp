#include "ball.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Ball::Ball(int screenwidth, int screenheigth)
{
	rect.w = _ballwidth;
	rect.h = _ballheigth;
	rect.x = screenwidth / 2 - rect.w / 2;
	rect.y = screenheigth / 2 - rect.h / 2;

	srand(time(0));
	int _randomNum = rand();
	int _randomNum2 = rand();

	if (_randomNum % 2 == 0)
		_motionX = -8;
	else _motionX = 8;

	if (_randomNum2 % 2 == 0)
		_motionY = -6;
	else _motionY = 6;
}

Ball::~Ball()
{

}

void Ball::render(Graphics &graphics,int r, int g, int b)
{
	_r = r;
	_g = r;
	_b = b;

	SDL_SetRenderDrawColor(graphics.getRenderer(), _r, _g, _b, 255);

	SDL_RenderFillRect(graphics.getRenderer(), &rect);
}

void Ball::update(int screenwidth, int screenheigth, SDL_Rect paddle1, SDL_Rect paddle2, Serial arduino)
{
	    srand(time(0));
	    int _randomNum = 2 + (rand() % 9);
		int _randomNum2 = rand();
		int _randomNum3 = 1 + rand();


		rect.x += _motionX;
		rect.y += _motionY;

		if (checkCollision(screenwidth, screenheigth, paddle1) == 2)
		{
			_motionY = _motionY * -1;
		}

		if (score(screenwidth,arduino) == true)
		{
			rect.x = screenwidth / 2 - rect.w / 2;
			rect.y = screenheigth / 2 - rect.h / 2;

			if (_randomNum3 % 2 == 0)
				_motionX = -8;
			else _motionX = 8;

			if (_randomNum2 % 2 == 0)
				_motionY = -6;
	        else _motionY = 6;
		}

		if (checkCollision(screenwidth, screenheigth, paddle1) == 1)
		{
			_motionX = _motionX * -1;
			_motionY = _randomNum;
			if (_randomNum2 % 2 == 0)
				_motionY = _motionY * -1;
		}

		if (checkCollision(screenwidth, screenheigth, paddle2) == 1)
		{
			_motionX = _motionX * -1;
			_motionY = _randomNum;
			if (_randomNum2 % 2 == 0)
				_motionY = _motionY * -1;
		}

}


int Ball::checkCollision(int screenwidth, int screenheigth, SDL_Rect paddle)
{
	if(cornerInRect(rect.x, rect.y, paddle) == true || cornerInRect(rect.x, rect.y + rect.h, paddle) == true ||
			cornerInRect(rect.x + rect.w, rect.y, paddle) == true || cornerInRect(rect.x + rect.w, rect.y + rect.h, paddle) == true)
		return 1; //hit off paddle


	if (rect.y <= 0 || rect.y >= screenheigth - rect.h)
		return 2; //hits ceiling or floor


	return 0; 
}

bool Ball::cornerInRect(int x, int y, SDL_Rect paddle)
{
	if (x > paddle.x && y > paddle.y && x < paddle.x + paddle.w && y < paddle.y + paddle.h)
		return true;

	return false;
}

bool Ball::score(int screenwidth, Serial arduino)
{
	if (rect.x > screenwidth - 5 - rect.w)
	{
		_score1++;
		std::cout << _score2 << ":" << _score1 << std::endl;
		if (_score1 == 3)
			_score1 = 0;

		switch (_score1)
		{
		case 1:
				arduino.WriteData("1", 255);
				break;
		case 2:
				arduino.WriteData("2", 255);
				break;
		case 3:
				arduino.WriteData("3", 255);
				break;
		}

		return true;
	}
	if (rect.x < 5)
	{
		_score2++;
		std::cout << _score2 << ":" << _score1 << std::endl;
		if (_score2 == 3)
			_score2 = 0;

		return true;
	}

}


void Ball::bot(Paddle &paddle, int screenwidth, int screenheigth)
{
	while (paddle.getY() + paddle.getH() / 2 > rect.y && paddle.getY() != 0 && rect.x > screenwidth / 2 - 150)
	{
		paddle.move(screenwidth, screenheigth, true);
	}

	while (paddle.getY() + paddle.getH() < rect.y && paddle.getY() != screenheigth && rect.x > screenwidth / 2 - 150)
	{
		paddle.move(screenwidth, screenheigth, false);
	}
}