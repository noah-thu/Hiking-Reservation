/*
	Syntax Sorcerers

	Thu, Kaung (Team Leader)
	Hua, Irene (20125)

	Fall 2024
	CS A250 C++ 2

	Outdoor Adventures
*/

#include "Reservations.h"

#include <iostream>
#include <iomanip>

using namespace std;

int Reservations::addReservation(int memberID, const string& hikeName)
{
	Node* newNode = new Node(memberID, hikeName, last, nullptr);
	
	if (first == nullptr)
	{
		first = newNode;
		newNode->setReservationNo(RESERVATION_NUMBER);
	}
	else
	{
		last->setNext(newNode);
		newNode->setReservationNo(last->getReservation() + 1);
	}
	last = newNode;

	return newNode->getReservation();
}

void Reservations::cancelReservation(int reservation)
{
	Node* toDelete = findReservation(reservation);

	if (first->getReservation() == reservation)
	{
		first = first->getNext();
		first->setPrev(nullptr);
		delete toDelete;
		toDelete = nullptr;
	}

	else if (last->getReservation() == reservation)
	{
		last = last->getPrev();
		last->setNext(nullptr);
		delete toDelete;
		toDelete = nullptr;
	}
		
	else
	{
		Node* prevNode = toDelete->getPrev();
		Node* nextNode = toDelete->getNext();

		if (prevNode) // to check it's not the first node
		{
			prevNode->setNext(nextNode);
		}
		if (nextNode)
		{
			nextNode->setPrev(prevNode);
		}
	}
	delete toDelete;
	toDelete = nullptr;
}

void Reservations::printReservation(int reservation, const HikeList& hikeList,
	const MemberList& memberList) const
{
	cout << endl; // keep it
	Node* temp = findReservation(reservation);
	hikeList.printByHikeName(temp->getHikeName());

	double regPrice = hikeList.getPrice(temp->getHikeName());
	double afterPts = memberList.getPoints(temp->getMemberID()) / 100;
	double finalPrice = regPrice - afterPts;
	if (finalPrice != regPrice)
	{
		cout << fixed << setprecision(2) << "\n\tDiscounted price using points: $"
			<< finalPrice << endl;
	}
	cout << endl;
}

void Reservations::clearList()
{
	Node* toDelete = first;
	last = nullptr;

	while (toDelete != nullptr)
	{
		first = first->getNext();
		delete toDelete;
		toDelete = first;
	}
	first = nullptr;
	toDelete = nullptr;
	count = 0;
}

Reservations::~Reservations()
{
	clearList();
}

Node* Reservations::findReservation(int reservation) const
{
	Node* currentPtr = first;
	
	while (currentPtr->getReservation() != reservation)
	{
		currentPtr = currentPtr->getNext();
	}
	return currentPtr;
}
