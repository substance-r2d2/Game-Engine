#include <SDL\SDL.h>
#include <iostream>
#include <cstdlib>

#include "Errors.h"

void fatalError(std::string errorMessage)
{
	std::cout << errorMessage << std::endl;
	std::cout << "PRESS ANY KEY TO QUIT" << std::endl;
	int a;
	std::cin >> a;
	SDL_Quit();
	exit(420);
}
