#include "View.h"

void View::ClearScreen()
{
	system("cls");
}

void View::ViewStartScreen()
{
	std::string str1 = "  _____ _                  _____                      _____\n";
	std::string str2 = " |_   _(_)                |_   _|                    |_   _|\n";
	std::string str3 = "   | |  _  ___    ______    | | __ _  ___    ______    | | ___   ___ \n";
	std::string str4 = "   | | | |/ __|  |______|   | |/ _` |/ __|  |______|   | |/ _ \\ / _ \\ \n";
	std::string str5 = "   | | | | (__              | | (_| | (__              | | (_) |  __/\n";
	std::string str6 = "   \\_/ |_|\\___|             \\_/\\__,_|\\___|             \\_/\\___/ \\___| \n";
	std::cout << str1 << str2 << str3 << str4 << str5 << str6;
	Sleep(6000);
}

void View::ViewRules()
{
	View::ClearScreen();

	std::string rule = "To make a move, select a number from 1 to 9.\nYou can choose 2 game modes and 2 difficulty levels.\nHave a good game! ";
	std::cout << rule << std::endl;
	Sleep(5000);
	int N = rule.size();
	for (int i = N; i > 0; --i)
	{
		rule.erase(i, 1);
		ClearScreen();
		std::cout << rule << std::endl;
	}
}

void View::ViewSelectModeMessage()
{
	View::ClearScreen();
	std::cout << "Select the game mode:" << std::endl;
	std::cout << "1) Two players" << std::endl << "2) Player vs Bot" << std::endl;
}

void View::ViewSelectDifMessage()
{
	View::ClearScreen();
	std::cout << "Select the difficulty level:" << std::endl;
	std::cout << "1) Easy" << std::endl << "2) Hard" << std::endl;
}

void View::ViewBadNumberMessage(std::string message)
{
	View::ClearScreen();
	std::cout << "Incorrect number of " + message + ", please select again!" << std::endl;
}

void View::ViewSelectSideMessage()
{
	View::ClearScreen();
	std::cout << "Select your side :" << std::endl;
	std::cout << "1) X" << std::endl << "2) 0" << std::endl;
}

void View::ViewBadCoordsMessage()
{
	View::ClearScreen();
	std::cout << "Incorrect coordinates, try to enter again!" << std::endl;
}

void View::RefreshScreen(std::vector<short int> used_coords)
{
	View::ClearScreen();
	for (int i = 0; i < 9; ++i)
	{
		std::cout << '|';
		if (used_coords[i] == 1)
		{
			std::cout << 'X';
		}
		else if (used_coords[i] == -1)
		{
			std::cout << '0';
		}
		else
		{
			std::cout << ' ';
		}
		if (((i + 1) % 3) == 0)
		{
			std::cout << '|' << std::endl;
			if (i != 8)
			{
				std::cout << partition << std::endl;
			}

		}
	}
}

void View::ViewResultMessage(std::string side)
{
	std::cout << side << " WIN!" << std::endl;
}

void View::ViewEndMessage()
{
	std::string str1 = "  _____ _                 _            __                    _             _               _\n";
	std::string str2 = " |_   _| |               | |          / _|                  | |           (_)             | |\n";
	std::string str3 = "   | | | |__   __ _ _ __ | | _____   | |_ ___  _ __    _ __ | | __ _ _   _ _ _ __   __ _  | |\n";
	std::string str4 = "   | | | '_ \\ / _` | '_ \\| |/ / __|  |  _/ _ \\| '__|  | '_ \\| |/ _` | | | | | '_ \\ / _` | | |\n";
	std::string str5 = "   | | | | | | (_| | | | |  < \\__ \\  | || (_) | |     | |_) | | (_| | |_| | | | | | (_| | |_|\n";
	std::string str6 = "   \\_/ |_| |_|\\__,_|_| |_|_|\\_\\___/  |_| \\___/|_|     | .__/|_|\\__,_|\\__, |_|_| |_|\\__, | (_)\n";
	std::string str7 = "	                                              | |             __/ |         __/ |\n";
	std::string str8 = "	                                              |_|            |___/         |___/\n";
	std::cout << str1 << str2 << str3 << str4 << str5 << str6 << str7 << str8;
	Sleep(6000);
}