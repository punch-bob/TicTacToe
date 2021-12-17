#include "Game.h"
#include <vector>

Game::Game()
{
	mode = 2;
	difficult = 2;
	player_1 = nullptr;
	player_2 = nullptr;
	for (int i = 0; i < 9; ++i)
	{
		used_coord.push_back(0);
	}
}

void Game::CreatePlayers(int mode, int dif)
{
	player_1 = std::shared_ptr<Player>(new User);
	if (mode == 2)
	{
		if (dif == 1)
		{
			player_2 = std::shared_ptr<Player>(new EasyBot());
		}
		else
		{
			player_2 = std::shared_ptr<Player>(new HardBot);
		}
	}
	else
	{
		player_2 = std::shared_ptr<Player>(new User);
	}
}

bool Game::Step(int step)
{
	int sign = 0;
	std::shared_ptr<Player> player;
	if (step == 1)
	{
		player = player_1;
	}
	else
	{
		player = player_2;
	}
	if (player->side == 1)
	{
		sign = 1;
	}
	else
	{
		sign = -1;
	}
	int coords = controller.GetCoords(player, used_coord);
	used_coord[coords] = sign;
	return true;
}

void Game::Play()
{
	std::vector<int> game_set;
	game_set = controller.StartGame();
	mode = game_set[0];
	if ((mode & 1) == 0)
	{
		difficult = game_set[1];
	}

	int side = controller.SelectSide();

	CreatePlayers(mode, difficult);
	int step = 0;

	if (side == 1)
	{
		Game::player_1->side = 1;
		Game::player_2->side = -1;
		step = 1;
	}
	else
	{
		Game::player_1->side = -1;
		Game::player_2->side = 1;
		step = 2;
	}
	GameResult result = GameResult::PLAYING;

	while (result == GameResult::PLAYING)
	{
		controller.UpdateBoard(used_coord);
		Game::Step(step);
		result = controller.CheckWin(used_coord);
		step = (step + 1) % 2;
	}
	controller.UpdateBoard(used_coord);
	controller.GetWinMessage(result);
	controller.EndGame();
}