#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>
#include "Observer.h"

class View : public Observer
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

	void ViewResultMessage(std::string side);

	void ViewEndMessage();

	void Update(std::vector<short int> used_coords);
private:
	std::string partition = "+-+-+-+";
};