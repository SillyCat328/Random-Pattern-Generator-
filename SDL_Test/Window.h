#pragma once
#include "Config.h"
void ErrorCheck() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not be initialised: " << SDL_GetError();
	}
	else
	{
		std::cout << "SDL video system is ready to go\n";
	}
}