#include <iostream>
#include <SDL.h>
#include "game.h"



int main(int argv, char * argc[])
{
	int game_init;
	int ard_init;

	std::cout << "Press 1 for keyboard inputs, or press 2 for arduino inputs." << std::endl;
	std::cout << "Arduino can be used to control the left paddle and change the colour of the layout." << std::endl;
	std::cin >> ard_init;
	std::cout << "Press 1 to start the game." << std::endl;
	std::cin >> game_init;

	while (game_init == 1)
	{
		if (ard_init == 1)
			Game NewGame(false);

		if (ard_init == 2)
			Game NewGame(true);

	}

	return 0;
}