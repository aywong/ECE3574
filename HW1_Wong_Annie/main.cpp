/*
Annie Wong
9055-27808
aywong@vt.edu
ECE3574
Homework 1
9/10/2012
*/

#include "roomRez.h"

/*
    This applications takes user input to add/delete and list room reservations

    Commands are as follows:

    * roomRez
    (no parameters: list reservations)
    * roomRez -add -r room -d date -t hour
    (-add: adds a new reservation)
    * roomRez -del confirm#
    (-del: deletes an entry using the confirmation number)
    * roomRez -list -d date
    (-list: prints room reservations for a date (-d) or room (-r))
    * roomRez -h
    (-help: prints out help menu)

    This  applications iscase-insensitivity

    Reservations will be stored as:
    confirmNum-room-date-hour1-hour2
*/

int main(int argc, char *argv[])
{
    roomRez myRez;

    // no parameters
    if ( argc == 1 )
	{
        myRez.printRez();
	}
    else if (argc == 2)
    {
         myRez.printHelp();
    }
    else if (argc == 3)
    {
        QString confirmNum = argv[2];
        myRez.deleteRez(confirmNum);
    }
    else if (argc == 4)
	{
        QString inputString = argv[3];

        // check parameter
        switch(argv[2][1])
        {
            case 'd':
                myRez.printRezDate(inputString);
                break;
            case 'r':
                myRez.printRezRoom(inputString);
                break;
            default: printf("Invalid parameters, please try again.\n");

            myRez.printRezDate(inputString);
        }
	}
    else if (argc == 8)
    {
        QString room = argv[3];
        QString date = argv[5];
        QString hour = argv[7];

        myRez.addRez(room,date,hour);
    }
    else {
        myRez.printHelp();
    }

	return 0;
}
