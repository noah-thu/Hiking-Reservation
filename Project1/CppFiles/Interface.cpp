/*
    Syntax Sorcerers

    Thu, Kaung (Team Leader)
    Hua, Irene (20125)

    Fall 2024
    CS A250 C++ 2

    Outdoor Adventures
*/

#include "Interface.h"

#include <iostream>
#include <string>

using namespace std;

// Display menu
void displayMenu()
{
    cout << string(51,'*') << endl;
    cout << "                   HIKING IN THE US                 " << endl;
    cout << string(51,'*') << endl;
    cout << "\n\t1. Browse by location              " << endl;
    cout << "\t2. Browse by duration               " << endl;
    cout << "\t3. Browse by difficulty             " << endl;
    cout << "\t4. Browse by price                  " << endl;
    cout << "\t5. Make a reservation               " << endl;
    cout << "\t6. View reservation                 " << endl;
    cout << "\t7. Cancel reservation               " << endl;
    cout << "\t8. Exit                             " << endl;

    cout << "\nPlease make a selection: ";
}

// Process reservation
void processReservation(const HikeList& hikeList, MemberList& memberList,
    Reservations& reservations)
{
    int choice = 0;

    while (choice != 8)
    {
        cin >> choice;
        cin.ignore(); // Clear input buffer

        if (choice == 1)
        {
            chooseByLocation(hikeList, memberList, reservations);
        }
        else if (choice == 2)
        {
            chooseByDuration(hikeList, memberList, reservations);
        }
        else if (choice == 3)
        {
            chooseByDifficulty(hikeList, memberList, reservations);
        }
        else if (choice == 4)
        {
            chooseByPrice(hikeList, memberList, reservations);
        }
        else if (choice == 5)
        {
            makeReservation(hikeList, memberList, reservations);
        }
        else if (choice == 6)
        {
            viewReservation(hikeList, memberList, reservations);
        }
        else if (choice == 7)
        {
            cancelReservation(hikeList, memberList, reservations);
        }
        else if (choice == 8)
        {
            cout << "\nThank you for visiting!\n";
            choice = 8;
        }

        if (choice != 8)
        {
            system("Pause"); // Pause to let the user see the output
        }
        cout << endl;

        if (choice != 8)
        {
            displayMenu();
        }
        
    }
}

// Browse by location
void chooseByLocation(const HikeList& hikeList, MemberList& memberList, 
                    Reservations& reservations)
{
    hikeList.printAllLocations();
    cout << "Choose a location: ";
    string location;
    cin >> location;

    hikeList.printByLocation(location);
    askToReserve(hikeList, memberList, reservations);
}

// Browse by duration
void chooseByDuration(const HikeList& hikeList, MemberList& memberList, 
    Reservations& reservations)
{
    cout << "\nHow many days are you considering? ";
    int days = 0;
    cin >> days;
    cin.ignore(); // Clear input buffer

    hikeList.printByDuration(days);
    askToReserve(hikeList, memberList, reservations);
}

// Browse by difficulty
void chooseByDifficulty(const HikeList& hikeList, MemberList& memberList, 
    Reservations& reservations)
{
    cout << "\nChoose difficulty level:\n" << endl;
    cout << "\te. easy\n" << "\tm. moderate\n" << "\ts. strenous\n" << endl;
    cout << "Your choice: ";
    char difficulty = ' ';
    cin >> difficulty;

    hikeList.printByDifficulty(difficulty); // It only accepts char
    askToReserve(hikeList, memberList, reservations);
}

// Browse by price
void chooseByPrice(const HikeList& hikeList, MemberList& memberList, 
    Reservations& reservations)
{
    hikeList.printByPrice();
    askToReserve(hikeList, memberList, reservations);
}

// Ask if the user is a member
int askIfMember(MemberList& memberList)
{
    cout << "\nAre you a member? (y/n) ";
    char response = ' ';
    cin >> response;

    if (response == 'y')
    {
        cout << "\nWhat is your member ID number? ";
        int memberID = 0;
        cin >> memberID;
        cin.ignore(); // Clear input buffer

        cout << "\nWhat is your last name? ";
        string lastName;
        cin >> lastName;
        cout << endl;

        memberList.printMember(memberID, lastName);
        return memberID;
    }
    else
    {
        return addNewMember(memberList);
    }
}

// Add a new member
int addNewMember(MemberList& memberList)
{
    cout << "\n\tLet's add you to the member list!\n";
    cout << "\t\tWhat is your first name? ";
    string firstName;
    cin >> firstName;

    cout << "\t\tWhat is your last name?  ";
    string lastName;
    cin >> lastName;

    memberList.addMember(firstName, lastName);

    cout << "\n\tWelcome to the club!\n";
    cout << "\t\tYou member ID number is: " << memberList.getLastID() << endl;

    return memberList.getLastID();
}

// Making reservation
void makeReservation(const HikeList& hikeList, MemberList& memberList, 
    Reservations& reservations)
{
    int userID = askIfMember(memberList);

    cout << "\nWhich hike would you like to reserve (hike name)? ";
    string userHikeName;
    cin >> userHikeName;

    cout << endl;
    hikeList.printByHikeName(userHikeName);
    double regPrice = hikeList.getPrice(userHikeName);
    int pointsToDiscount = memberList.getPoints(userID) / 100; // Convert the points
    double discountedPrice = regPrice - pointsToDiscount;

    if (discountedPrice != regPrice)
    {
        cout << "\n\tDiscounted price using points: $" << discountedPrice << "\n";
    }
    cout << endl;

    int reservationNo = reservations.addReservation(userID, userHikeName);

    cout << "\tBefore proceeding, please make a note of your reservation number.\n";
    cout << "\t  Reservation #: " << reservationNo << "\n\n";
    cout << "( *** Will continue to scheduling and payment. *** )\n" << endl;
}

// Viewing the reservation by reservation number
void viewReservation(const HikeList& hikeList, MemberList& memberList, 
    Reservations& reservations)
{
    cout << "\nEnter reservation #: ";
    int temp = 0;
    cin >> temp;

    reservations.printReservation(temp, hikeList, memberList);
}

// Cancel the reservation
void cancelReservation(const HikeList& hikeList, MemberList& memberList, 
    Reservations& reservations)
{
    cout << "\nEnter resrevation #: ";
    int temp = 0;
    cin >> temp;

    reservations.printReservation(temp, hikeList, memberList);

    cout << "Are you sure you want to cancel this reservation? (y/n) ";

    char input = ' ';
    cin >> input;

    if (input == 'y')
    {
        reservations.cancelReservation(temp);
        cout << "\nReservation #" << temp << " has been canceled.\n" << endl;
    }
    else
    {
        cout << endl;
    }
}

void askToReserve(const HikeList& hikeList, MemberList& memberList, 
    Reservations& reservations)
{
    cout << "Would you like to make a reservation? (y/n) ";
    char temp = ' ';
    cin >> temp;

    if (temp == 'y')
    {
        makeReservation(hikeList, memberList, reservations);
    }
    else
    {
        cout << endl;
    }
}
