#include "HardBot.h"

int evaluation(std::vector<short int> board)
{
	int used_coord = 0;
	int win_case[8][3] = { {0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6} };
	for (int i = 0; i < 8; ++i)
	{
		if (board[win_case[i][0]] != 0 &&
			board[win_case[i][0]] == board[win_case[i][1]] &&
			board[win_case[i][0]] == board[win_case[i][2]])
		{
			return board[win_case[i][2]];
		}
	}
	return 0;
}

PlayerType HardBot::GetType()
{
	return PlayerType::HardBot;
}

int HardBot::MiniMax(std::vector<short int> board, int opponent_side)
{
	int winner = evaluation(board);
	if (winner != 0)
	{
		return winner * opponent_side;
	}

	int coords = -1;
	int score = -2;
	for (int i = 0; i < 9; ++i)
	{
		if (board[i] == 0)
		{
			board[i] = opponent_side;
			int thisScore = -HardBot::MiniMax(board, opponent_side * -1);
			if (thisScore > score)
			{
				score = thisScore;
				coords = i;
			}
			board[i] = 0;
		}
	}
	if (coords == -1)
	{
		return 0;
	}
	return score;
}

int HardBot::GetCoords(std::vector<short int> board)
{
	int opponent_side = 0;
	int coords = -1;
	int score = -2;

	if (HardBot::side == 1)
	{
		opponent_side = -1;
	}
	else
	{
		opponent_side = 1;
	}

	for (int i = 0; i < 9; ++i)
	{
		if (board[i] == 0)
		{
			board[i] = HardBot::side;
			int temp_score = -HardBot::MiniMax(board, opponent_side);
			board[i] = 0;
			if (temp_score > score)
			{
				score = temp_score;
				coords = i;
			}
		}
	}
	return coords;
}