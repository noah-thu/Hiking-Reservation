/*
    Syntax Sorcerers

    Thu, Kaung (Team Leader)
    Hua, Irene (20125)

    Fall 2024
    CS A250 C++ 2

    Outdoor Adventures
*/

#include "MemberList.h"
#include "Reservations.h"

#include <iostream>

using namespace std;

// MemberList: copy constructor
MemberList::MemberList(const MemberList& otherMemberList)
{
	memberList = new set<Member>(*otherMemberList.memberList);
}

// MemberList: copy assignment operator
MemberList& MemberList::operator=(const MemberList& otherMemberList)
{
    // Self-assignment check
    if (&otherMemberList == this)
    {
        cerr << "Attempted assignment to itself.\n";
        return *this;
    }
    memberList = new set<Member>(*otherMemberList.memberList);

    return *this;
}

// Reservations: copy constructor
Reservations::Reservations(const Reservations& reservation)
{
    // Initialize an empty list
    first = nullptr;
    last = nullptr;
    count = 0;

    // Copy nodes using addReservation
    Node* currentSource = reservation.first;
    while (currentSource != nullptr)
    {
        addReservation(currentSource->getMemberID(), currentSource->getHikeName());
        currentSource = currentSource->getNext();
    }
}

// Reservations: copy assignment operator
Reservations& Reservations::operator=(const Reservations& reservation)
{
    if (&reservation == this)
    {
        cerr << "Attempted assignment to itself.\n";
        return *this;
    }
    else if (reservation.count == 0)
    {
        clearList();
    }
    else if (this->count == 0)
    {
        copyCallingObjIsEmpty(reservation);
    }
    else if (this->count == reservation.count)
    {
        copyObjectsSameLength(reservation);
    }
    else if (this->count > reservation.count)
    {
        copyCallingObjLonger(reservation);
    }
    else
    {
        copyCallingObjShorter(reservation);
    }

    return *this;
}

// Reservations: copyCallingObjIsEmpty
void Reservations::copyCallingObjIsEmpty(const Reservations& reservation)
{
    Node* current = reservation.first;

    while (current != nullptr)
    {
        this->addReservation(current->getMemberID(), current->getHikeName());
        current = current->getNext();
    }
}

// Reservations: copyObjectsSameLength
void Reservations::copyObjectsSameLength(const Reservations& reservation)
{
    Node* current = reservation.first;
    Node* thisCurrent = this->first;

    while (current != nullptr)
    {
        thisCurrent->setReservationNo(current->getReservation());
        thisCurrent->setMemberID(current->getMemberID());
        thisCurrent->setHikeName(current->getHikeName());

        current = current->getNext();
        thisCurrent = thisCurrent->getNext();
    }
}

// Reservations: copyCallingObjLonger
void Reservations::copyCallingObjLonger(const Reservations& otherReservation)
{
    Node* current = first;
    Node* paramCurrent = otherReservation.first;

    while (paramCurrent != nullptr)
    {
        current->setReservationNo(paramCurrent->getReservation());
        current->setMemberID(paramCurrent->getMemberID());
        current->setHikeName(paramCurrent->getHikeName());

        paramCurrent = paramCurrent->getNext();
        current = current->getNext();
    }

    last = current->getPrev();

    while (current != nullptr)
    {
        Node* temp = current->getNext();
        delete current;
        current = temp;
    }
    last->setNext(nullptr);
    count = otherReservation.count;
}

// Reservations: copyCallingObjShorter
void Reservations::copyCallingObjShorter(const Reservations& reservation)
{
    Node* current = reservation.first;
    Node* thisCurrent = this->first;
    while (current != nullptr && thisCurrent != nullptr)
    {
        thisCurrent->setReservationNo(current->getReservation());
        thisCurrent->setMemberID(current->getMemberID());
        thisCurrent->setHikeName(current->getHikeName());

        current = current->getNext();
        thisCurrent = thisCurrent->getNext();
    }

    while (current != nullptr)
    {
        this->addReservation(current->getMemberID(), current->getHikeName());
        current = current->getNext();
    }
}