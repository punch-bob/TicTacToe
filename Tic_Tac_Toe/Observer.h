#pragma once
class Observer
{
public:
	virtual void Update(std::vector<short int> used_coords) = 0;
};

