#include <SDL.h>
#include <iostream>
#include <cmath>

#include "game.h"
#include "graphics.h"
#include "paddle.h"
#include "ball.h"
#include "serial.h"

int screenwidth = 800;
int screenheigth = 500;

Paddle player1(screenwidth,screenheigth,1);
Paddle player2(screenwidth,screenheigth,2);
Ball ball(screenwidth, screenheigth);

char* port_name = "COM3";
Serial arduino(port_name);
int count = 0;

Game::Game(bool input)
{
	_input = input;
	SDL_Init(SDL_INIT_EVERYTHING);
	std::cout << "Game initalised!" << std::endl;

	loop();

}

Game::~Game()
{

}

void Game::loop()
{
	Graphics graphics(screenwidth, screenheigth);

	SDL_Event events;

	int startTicks;

	while (true)
	{
		startTicks = SDL_GetTicks();

		if (SDL_PollEvent(&events))
			if (events.type == SDL_QUIT)
				return;

		logic();

		draw(graphics);

		Uint32 frameTicks = SDL_GetTicks() - startTicks;
		if (1000 / 30 > frameTicks)
			SDL_Delay(1000 / 30 - frameTicks);

	}
}

void Game::logic()
{
	//player movements
	const Uint8 *keystates = SDL_GetKeyboardState(NULL);

	if (keystates[SDL_SCANCODE_DOWN])
		player1.move(screenwidth, screenheigth, false);

	if (keystates[SDL_SCANCODE_UP])
		player1.move(screenwidth, screenheigth, true);

	if (_input)
	{
		if (arduino.inputStatus(arduino) == 2)
			player1.move(screenwidth, screenheigth, false);

		if (arduino.inputStatus(arduino) == 3)
			player1.move(screenwidth, screenheigth, true);
	}

	if (keystates[SDL_SCANCODE_S])
		player2.move(screenwidth, screenheigth, false);

	if (keystates[SDL_SCANCODE_W])
	player2.move(screenwidth, screenheigth, true);
	
	ball.update(screenwidth,screenheigth, player1.getRect(),player2.getRect(), arduino);

	ball.bot(player2, screenwidth, screenheigth);
}

void Game::draw(Graphics &graphics)
{
	SDL_Rect line;
	line.w = 2;
	line.x = screenwidth / 2 - line.w;
	line.y = 0;
	line.h = screenheigth;

	int r1, g1, b1, r2, g2, b2;

	if (_input)
	{
		if (arduino.inputStatus(arduino) == 0)
		{
			count++;
		}
		if (count % 2 != 0)
		{
			r1 = 255;
			g1 = 255;
			b1 = 255;

			r2 = 0;
			g2 = 0;
			b2 = 0;
		}
		if (count % 2 == 0)
		{
			r1 = 0;
			g1 = 0;
			b1 = 0;

			r2 = 255;
			g2 = 255;
			b2 = 255;
		}
	}

	if (!_input)
	{
		r1 = 0;
		g1 = 0;
		b1 = 0;

		r2 = 255;
		g2 = 255;
		b2 = 255;
	}
	graphics.clear();
	//paddle
	player1.render(graphics,r1,g1,b1);
	player2.render(graphics, r1, g1, b1);
	//ball
	ball.render(graphics, r1, g1, b1);
	//centre line
	SDL_SetRenderDrawColor(graphics.getRenderer(), r1, g1, b1, 255);
	SDL_RenderFillRect(graphics.getRenderer(), &line);
	//background
	SDL_SetRenderDrawColor(graphics.getRenderer(), r2, g2, b2, 255);

	graphics.flip();

}

