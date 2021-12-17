#pragma once
#include "Player.h"

class User : public Player
{
public:

	PlayerType GetType();

	int GetCoords(std::vector<short int> board);

	virtual ~User() {}
private:
	
};