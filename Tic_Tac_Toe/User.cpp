#include "User.h"
#include <string>

PlayerType User::GetType()
{
	return PlayerType::User;
}

int User::GetCoords(std::vector<short int> used_coords)
{
	std::string coord;
	std::cin >> coord;
	return std::stoi(coord) - 1;
}