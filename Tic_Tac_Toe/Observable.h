#pragma once
#include <algorithm>

class Observable
{
	std::vector<Observer*> observers;
public:
	void RegisterObserver(Observer* observer)
	{
		observers.push_back(observer);
	}

	void UnregisterObserver(Observer* observer)
	{
		observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
	}

	void Notify(const std::vector<short int>& used_coords) 
	{
		for (auto& observer : observers)
		{
			observer->Update(used_coords);
		}
	}
};

