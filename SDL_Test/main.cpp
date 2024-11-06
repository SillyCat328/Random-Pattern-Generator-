//Using SDL and standard IO
#include "Config.h"

int main(int argc, char* args[]) {

	const int WIDTH_WIN = 50;
	const int HEIGHT_WIN = 50;

	bool IsProgramRunning = true;

	int x = 25;
	int y = 25;

	// Random Colour
	unsigned int r = 0;
	unsigned int g = 0;
	unsigned int b = 0;
	RandomNumberGen gen;


	// Random position
	std::random_device P_rd;
	std::uniform_int_distribution<unsigned int> nd(0, 4);

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	SDL_CreateWindowAndRenderer(WIDTH_WIN * 20, HEIGHT_WIN * 20, 0, &window, &renderer);
	SDL_RenderSetScale(renderer, 20, 20);

	while (IsProgramRunning) 
	{
		unsigned int P_uid = nd(P_rd);


		SDL_Event e;
		while (SDL_PollEvent(&e) > 0)
		{
			switch (e.type)
			{
			case SDL_QUIT:
				IsProgramRunning = false;
			default:
				break;
			}
			SDL_UpdateWindowSurface(window);
		}
		// position change
		switch (P_uid)
		{

		case 0: 
			x -= 1;
			y -= 1;
			break;
		
		case 1:
			x += 1;
			y -= 1;
			break;
		
		case 2: 
			x -= 1;
			y += 1;
			break;
		
		case 3:
			x += 1;
			y += 1;
			break;
		
		}
		

		r = gen.random_int(0, 255);
		g = gen.random_int(0, 255/2);
		b = gen.random_int(0, 255/4);
	

		SDL_SetRenderDrawColor(renderer, r, g, b, 255);
		SDL_RenderDrawPoint(renderer, x, y);
		SDL_RenderPresent(renderer);

		if (x > 50 || x < 0 || y > 50 || y < 0) {
			 x = 25;
			 y = 25;
		}
		SDL_Delay(50);
	}

	return 0;
}

