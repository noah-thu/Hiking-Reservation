/*
	Syntax Sorcerers

	Thu, Kaung (Team Leader)
	Hua, Irene (20125)

	Fall 2024
	CS A250 C++ 2

	Outdoor Adventures
*/

#include "Member.h"

#include <iostream>

using namespace std;

void Member::addPoints(int morePoints)
{
	points += morePoints;
}

void Member::setID(int newID)
{
	id = newID;
}

int Member::getID() const
{
	return id;
}

string Member::getLastName() const
{
	return lastName;
}

int Member::getPoints() const
{
	return points;
}

void Member::printMember() const
{
	cout << "\t" << lastName << ", " << firstName << endl;
	cout << "\t" << "Points available: " << points << endl;
}

bool Member::operator<(const Member& otherMember) const
{
	return id < otherMember.id;
}