/*
    Syntax Sorcerers

    Thu, Kaung (Team Leader)
    Hua, Irene (20125)

    Fall 2024
    CS A250 C++ 2

    Outdoor Adventures
*/

#include "Hike.h"
#include "HikeList.h"
#include "Member.h"
#include "MemberList.h"
#include "HikeReader.h"
#include "MemberReader.h"
#include "ReservationReader.h"
#include "Interface.h"

#include <iostream>

using namespace std;

int main()
{
    MemberList memberList;
    HikeList hikeList;
    Reservations reservations;

    getMemberData(memberList);
    getHikeData(hikeList);
    getReservationData(reservations);

    displayMenu();

    processReservation(hikeList, memberList, reservations);

    system("Pause");

    return 0;
}