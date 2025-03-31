/*
    Syntax Sorcerers

	Thu, Kaung (Team Leader)
    Hua, Irene (20125)

	Fall 2024
	CS A250 C++ 2

	Outdoor Adventures
*/

#ifndef RESERVATIONREADER_H
#define RESERVATIONREADER_H

#include "Reservations.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string RESERVATIONS_FILE = "reservations_database.txt";

void createReservation(ifstream& infile, Reservations& reservations)
{
	int id = 0;
	string hikeName;

	while (!infile.eof())
	{
		infile >> id >> hikeName;
		reservations.addReservation(id, hikeName);
	}
}

void getReservationData(Reservations& reservations)
{
	ifstream infile;

	infile.open(RESERVATIONS_FILE);

	if (!infile)
	{
		cerr << RESERVATIONS_FILE << " does not exist." << endl;
		exit(1); // terminates program
	}

	createReservation(infile, reservations);

	infile.close();
}
#endif