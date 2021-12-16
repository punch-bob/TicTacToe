#pragma once
#include <vector>
#include "Player.h"

class EasyBot : public Player
{
public:

	PlayerType GetType();

	int GetCoords();
private:
	virtual ~EasyBot() {};

	int GetCoords(std::vector<short int> board) { return 1; };
};