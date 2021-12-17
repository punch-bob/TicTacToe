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

	~Game() = default;

	void Play();

	void CreatePlayers(int mode, int dif);

	bool Step(int step);
private:
	int mode;
	int difficult;
	Controller controller;
	std::shared_ptr<Player> player_1;
	std::shared_ptr<Player> player_2;
	std::vector<short int> used_coord;
};