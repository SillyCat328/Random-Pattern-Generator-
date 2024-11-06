#include "RandomNumberGen.h"

int RandomNumberGen::random_int(int min, int max)
{
	time_t current_time = time(NULL);

	srand((unsigned) time(NULL));

	int random = min +  (rand() % max);

	std::cout << random << "\n";

	return random;
}
