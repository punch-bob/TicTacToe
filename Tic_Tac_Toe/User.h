#pragma once
#include "Player.h"

class User : public Player
{
public:

	PlayerType GetType();

	int GetCoords();
private:
	int GetCoords(std::vector<short int> board) { return 1; };

	virtual ~User() {}
};