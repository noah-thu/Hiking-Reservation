/*
    Syntax Sorcerers

	Thu, Kaung (Team Leader)
    Hua, Irene (20125)

	Fall 2024
	CS A250 C++ 2

	Outdoor Adventures
*/

#include "Hike.h"

#include <iostream>

using namespace std;

ostream& operator<<(ostream& out, const Hike& aHike)
{
	out << "\t" << aHike.hikeName << " (" << aHike.location << ")\n";
	out << "\t  " << "Difficulty: ";
    switch (aHike.difficulty)
    {
    case 'e':
        out << "easy";
        break;
    case 'm':
        out << "moderate";
        break;
    case 's':
        out << "strenuous";
        break;
    }
    out << endl;
	out << "\t  " << "Duration: " << aHike.duration << " day(s)" << endl;

	return out;
}

string Hike::getLocation() const
{
	return location;
}

int Hike::getDuration() const
{
	return duration;
}

char Hike::getDifficulty() const
{
	return difficulty;
}

string Hike::getHikeName() const
{
	return hikeName;
}

bool Hike::operator<(const Hike& otherHike) const
{
	return location < otherHike.location;
}