#include "EasyBot.h"

PlayerType EasyBot::GetType()
{
	return PlayerType::EasyBot;
}

int EasyBot::GetCoords(std::vector<short int> used_coords)
{
	srand(static_cast<unsigned int>(time(0)));
	int coords = rand() % 9;
	while (used_coords[coords] != 0)
	{
		coords = rand() % 9;
	}
	return coords;
}