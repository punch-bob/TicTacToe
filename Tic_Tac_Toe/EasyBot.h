#pragma once
#include <vector>
#include "Player.h"

class EasyBot : public Player
{
public:

	PlayerType GetType();

	int GetCoords(std::vector<short int> board);

	virtual ~EasyBot() {};
};