/*
	Syntax Sorcerers

	Thu, Kaung (Team Leader)
	Hua, Irene (20125)

	Fall 2024
	CS A250 C++ 2

	Outdoor Adventures
*/

#include "HikeList.h"

#include <iostream>
#include <iomanip>

using namespace std;

void HikeList::addHike(const Hike& hike, double price)
{
	hikeList.insert({hike, price});
}

void HikeList::addHike(const string& location, const string& hikeName, int duration,
	char difficulty, double price)
{
	Hike hike(location, hikeName, duration, difficulty);
	hikeList.insert({ hike, price });
}

double HikeList::getPrice(const string& hikeName) const
{
	auto iter = find_if(hikeList.begin(), hikeList.end(), [&hikeName](const auto& elem) 
		{ return elem.first.getHikeName() == hikeName; });

	return iter->second;
}

void HikeList::printAllLocations() const
{
	auto iter = hikeList.begin();
	auto iterEnd = hikeList.end();
	cout << endl;
	while (iter != iterEnd)
	{
		cout << "\t" << iter->first.getLocation() << endl;
		iter = hikeList.upper_bound(iter->first);
	}
	cout << endl;
}

void HikeList::printByLocation(const string& location) const
{
	cout << endl;
	auto iter = find_if(hikeList.begin(), hikeList.end(), 
		[&location](const auto& temp)
		{ return temp.first.getLocation() == location; });
	auto iterEnd = hikeList.end();

	while (iter != iterEnd && iter->first.getLocation() == location)
	{
		cout << iter->first;
		cout << fixed << setprecision(2) << "\t  Price (per person): $ " 
			<< iter->second << endl;
		++iter;
		cout << endl;
	}
}

void HikeList::printByDuration() const
{
	multimap<int, string> temp;

	for (const auto& elem : hikeList)
	{
		string hikeName = elem.first.getHikeName();
		string hikeLocation = elem.first.getLocation();

		string hikeDetails = hikeName + ", " + hikeLocation;

		temp.insert({ elem.first.getDuration(), hikeDetails });
	}

	for (const auto& elem : temp)
	{
		cout << "\t(" << elem.first;
		cout << ")" << " " << elem.second << endl;
	}
}

void HikeList::printByDuration(int days) const
{
	cout << endl;
	for (const auto& elem : hikeList)
	{
		if (elem.first.getDuration() == days)
		{
			cout << elem.first;
		}
	}
}

void HikeList::printByDifficulty(char difficulty) const
{
	cout << endl;
	cout << "\t(difficulty level)" << endl;
	for (auto& elem : hikeList)
	{
		if (elem.first.getDifficulty() == difficulty)
		{
			cout << "\t(" << elem.first.getDifficulty() << ") " 
				<< elem.first.getHikeName()
				<< ", " << elem.first.getLocation() << endl;
		}
	}
	cout << endl;
}

void HikeList::printByPrice() const
{
	multimap<double, pair<string, string>> tempMap;
	
	cout << endl;
	for (auto& elem : hikeList)
	{
		tempMap.emplace(elem.second, make_pair(elem.first.getHikeName(), 
			elem.first.getLocation()));
	}

	for (const auto& toPrint : tempMap)
	{
		cout << fixed << setprecision(2);

		cout << "\t$ " << setw(7) << toPrint.first << " - "
			<< toPrint.second.second << "(" << toPrint.second.first
			<< ")" << endl;
	}
	cout << endl;
}

void HikeList::printByHikeName(const string& hikeName) const
{
	auto iter = find_if(hikeList.begin(), hikeList.end(), 
		[&hikeName](const auto& elem)
		{ return elem.first.getHikeName() == hikeName; });

	if (iter != hikeList.end())
	{
		cout << iter->first;
		cout << fixed << setprecision(2) << "\t  $" 
			<< iter->second << endl;
	}
}

void HikeList::clearList()
{
	hikeList.clear();
}
