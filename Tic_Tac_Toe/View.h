#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>

class View
{
public:
	void ClearScreen();

	void ViewStartScreen();

	void ViewRules();

	void ViewSelectModeMessage();

	void ViewSelectDifMessage();

	void ViewBadNumberMessage(std::string message);

	void ViewSelectSideMessage();

	void ViewBadCoordsMessage();

	void RefreshScreen(std::vector<short int> used_coords);

	void ViewResultMessage(std::string side);

	void ViewEndMessage();
private:
	std::string partition = "+-+-+-+";
};