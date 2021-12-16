#pragma once
#include <vector>
#include "Player.h"
#include "View.h"

enum class GameResult
{
	WINX, WIN0, DRAW, PLAYING
};

class Controller
{
public:
	std::vector<int> StartGame();

	int SelectSide();

	short int GetCoords(Player* player, std::vector<short int> board);

	void UpdateBoard(std::vector<short int> used_coords);

	GameResult CheckWin(std::vector<short int> used_coords);

	void GetWinMessage(GameResult res);

	void EndGame();
private:
	View screen;
};