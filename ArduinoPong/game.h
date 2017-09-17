#ifndef GAME_H
#define GAME_H

#include "graphics.h"

class Game
{
public:
	Game(bool input);
	~Game();
private:
	void loop();
	void draw(Graphics &graphics);
	void logic();
	bool _input;
};
#endif