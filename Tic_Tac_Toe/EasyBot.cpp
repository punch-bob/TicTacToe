#include "EasyBot.h"

PlayerType EasyBot::GetType()
{
	return PlayerType::EasyBot;
}

int EasyBot::GetCoords()
{
	srand(static_cast<unsigned int>(time(0)));
	return rand() % 9;
}