#include "Controller.h"

std::vector<int> Controller::StartGame()
{
	std::vector<int> game_set;
	int numb;
	screen.ViewStartScreen();
	screen.ViewRules();
	screen.ViewSelectModeMessage();
	std::cin >> numb;
	while (numb > 2 || numb < 1)
	{
		screen.ClearScreen();
		screen.ViewBadNumberMessage("mode");
		Sleep(2000);
		screen.ViewSelectModeMessage();
		std::cin >> numb;
	}
	game_set.push_back(numb);
	if (numb == 2)
	{
		screen.ViewSelectDifMessage();
		std::cin >> numb;
		while (numb > 2 || numb < 1)
		{
			screen.ClearScreen();
			screen.ViewBadNumberMessage("difficult");
			Sleep(2000);
			screen.ViewSelectDifMessage();
			std::cin >> numb;
		}
		game_set.push_back(numb);
	}
	screen.ClearScreen();
	return game_set;
}

int Controller::SelectSide()
{
	int numb;
	screen.ViewSelectSideMessage();
	std::cin >> numb;
	while (numb > 2 || numb < 1)
	{
		screen.ClearScreen();
		screen.ViewBadNumberMessage("side");
		Sleep(2000);
		screen.ViewSelectSideMessage();
		std::cin >> numb;
	}
	return numb;
}

short int Controller::GetCoords(Player* player, std::vector<short int> used_coords)
{
	PlayerType player_type = player->GetType();
	short int coords;
	if (player_type == PlayerType::HardBot)
	{
		coords = player->GetCoords(used_coords);
		return coords;
	}

	coords = player->GetCoords();

	while (used_coords[coords] != 0 || (coords < 0 || coords > 8))
	{
		if (player_type == PlayerType::User)
		{
			screen.ViewBadCoordsMessage();
			Sleep(1000);
			screen.RefreshScreen(used_coords);
			coords = player->GetCoords();
		}
		else if (player_type == PlayerType::EasyBot)
		{
			coords = player->GetCoords();
		}
	}
	return coords;
}

void Controller::UpdateBoard(std::vector<short int> used_coords)
{
	screen.RefreshScreen(used_coords);
}

GameResult Controller::CheckWin(std::vector<short int> used_coords)
{
	int win_case[8][3] = { {0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6} };
	int used_coord = 0;
	for (int i = 0; i < 8; ++i)
	{
		if (used_coords[win_case[i][0]] != 0 &&
			used_coords[win_case[i][0]] == used_coords[win_case[i][1]] &&
			used_coords[win_case[i][0]] == used_coords[win_case[i][2]])
		{
			if (used_coords[win_case[i][2]] == 1)
			{
				return GameResult::WINX;
			}
			else if (used_coords[win_case[i][2]] == -1)
			{
				return GameResult::WIN0;
			}
		}
	}
	for (int i = 0; i < 9; ++i)
	{
		if (used_coords[i] != 0)
		{
			used_coord++;
		}
	}
	if (used_coord == 9)
	{
		return GameResult::DRAW;
	}
	return GameResult::PLAYING;
}

void Controller::GetWinMessage(GameResult res)
{
	screen.ClearScreen();
	if (res == GameResult::WINX)
	{
		screen.ViewResultMessage("X");
	}
	else if (res == GameResult::WIN0)
	{
		screen.ViewResultMessage("0");
	}
	else
	{
		screen.ViewResultMessage("NO ONE");
	}
	Sleep(5000);
}

void Controller::EndGame()
{
	screen.ClearScreen();
	screen.ViewEndMessage();
}