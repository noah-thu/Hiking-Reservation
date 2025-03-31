/*
	Syntax Sorcerers

	Thu, Kaung (Team Leader)
	Hua, Irene (20125)

	Fall 2024
	CS A250 C++ 2

	Outdoor Adventures
*/

#ifndef HIKE_H
#define HIKE_H

#include <string>

class Hike
{
friend std::ostream& operator<<(std::ostream& out, const Hike& aHike);
	 
public:
	Hike(std::string theLocation, std::string theHikeName, int theDuration,
		char theDifficulty)
		: location(theLocation), hikeName(theHikeName), duration(theDuration),
		difficulty(theDifficulty) {}

	std::string getLocation() const;
	int getDuration() const;
	char getDifficulty() const;
	std::string getHikeName() const;

	bool operator<(const Hike& otherHike) const;

private:
	std::string location;
	std::string hikeName;
	int duration;
	char difficulty;
};
#endif
