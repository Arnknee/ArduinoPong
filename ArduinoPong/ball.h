#ifndef BALL_h
#define BALL_h

#include "graphics.h"
#include "paddle.h"
#include "serial.h"

class Ball
{
public:
	SDL_Rect rect;
	Ball(int screenwidth, int screenheigth);
	~Ball();

	void render(Graphics &graphics, int r, int g, int b);

	void update(int screenwidth, int screenheigth, SDL_Rect paddle1, SDL_Rect paddle2, Serial arduino);

	int checkCollision(int screenwidth, int screenheigth, SDL_Rect paddle);

	bool score(int screenwidth, Serial arduino);

	void bot(Paddle &paddle, int screenwidth, int screenheigth);

	int getY();
	int getX();
private:
	int _ballwidth = 20;
	int _ballheigth = 20;

	int _score1 = 0;
	int _score2 = 0;

	int _motionX;
	int _motionY;

	int _r, _g, _b;

	bool cornerInRect(int x, int y, SDL_Rect paddle);
	
};
#endif