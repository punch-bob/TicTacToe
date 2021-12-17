#pragma once
#include <iostream>
#include <conio.h>
#include <vector>

enum class PlayerType
{
	EasyBot, HardBot, User
};

class Player
{
public:
	int side;

	virtual ~Player() {}

	virtual PlayerType GetType() = 0;

	virtual int GetCoords(std::vector<short int> board) = 0;
};