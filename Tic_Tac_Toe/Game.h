#pragma once
#include <iostream>
#include <vector>
#include "View.h"
#include "Controller.h"
#include "Player.h"
#include "EasyBot.h"
#include "HardBot.h"
#include "User.h"

class Game
{
public:
	Game();

	void Play();

	void CreatePlayers(int mode, int dif);

	bool Step(int step);

	void CreateBoard();
private:
	int mode;
	int difficult;
	Controller controller;
	Player* player_1;
	Player* player_2;
	std::vector<short int> used_coord;
};