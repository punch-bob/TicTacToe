#pragma once
#include "Player.h"

class HardBot : public Player
{
public:
	virtual ~HardBot() {};

	PlayerType GetType();

	int GetCoords(std::vector<short int> board);
private:
	int MiniMax(std::vector<short int> board, int side);

	int GetCoords() { return 1; };
};