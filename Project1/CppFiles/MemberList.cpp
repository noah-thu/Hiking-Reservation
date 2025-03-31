/*
	Syntax Sorcerers

	Thu, Kaung (Team Leader)
	Hua, Irene (20125)

	Fall 2024
	CS A250 C++ 2

	Outdoor Adventures
*/

#include "MemberList.h"

#include <iostream>
#include <algorithm>

using namespace std;

static int currentID = START_ID;

MemberList::MemberList()
{
	memberList = new set<Member>();
}

void MemberList::addMember(const string& firstName, const string& lastName)
{
	Member newMember(firstName, lastName);
	newMember.setID(currentID++);
	memberList->insert(newMember);
}

void MemberList::addMember(const string& firstName, const string& lastName, 
						   int points)
{
	Member newMember(firstName, lastName);
	newMember.addPoints(points);
	newMember.setID(currentID++);
	memberList->insert(newMember);
}

int MemberList::getLastID() const
{
	return (currentID - 1);
}

int MemberList::getPoints(int memberID) const
{
	auto iter = find_if(memberList->begin(), memberList->end(), 
		[&memberID](const Member& member)
		{ return member.getID() == memberID; });

	if (iter != memberList->end())
	{
		return iter->getPoints();
	}
	return -1;
}

void MemberList::printMember(int memberID, const string& lastName) const
{
	auto iter = find_if(memberList->begin(), memberList->end(),
		[&memberID](const Member& member)
		{ return member.getID() == memberID; });

	if (iter != memberList->end())
	{
		iter->printMember();
		cout << "\tMembership # " << iter->getID() << endl;
	}
}

void MemberList::clearList()
{
	memberList->clear();
}

MemberList::~MemberList()
{
	delete memberList;
	memberList = nullptr;
}