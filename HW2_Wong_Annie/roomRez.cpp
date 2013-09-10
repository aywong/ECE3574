/*
Annie Wong
9055-27808
aywong@vt.edu
ECE3574
Homework 1
9/10/2012
*/

#include "roomRez.h"

QFile roomRez::rezData("reservations.dat");
QTextStream roomRez::dataCout(stdout);

//	Default construtor: Stores content from the rezData.dat into a QStringList
roomRez::roomRez()
{
    rezData.open(QIODevice::ReadOnly);

    QTextStream readFile(&rezData);

    // read rezData until end of file
	while (!readFile.atEnd())
	{
        rezList << readFile.readLine();
	}

    rezData.close();
}

//	Deconstructor: write QStringList content to rezData.dat
roomRez::~roomRez()
{
    rezData.open(QIODevice::WriteOnly);

    QTextStream writeFile(&rezData);

    // write list into rezData.dat until end of file
    // pops list after data has been written
    while ( !rezList.isEmpty() )
	{
        writeFile << rezList.front() << endl;
        rezList.pop_front();
	}

    rezData.close();
}

//	Add reservations to rezList
void roomRez::addRez(QString room, QString date, QString hour)
{
    // convert date QString into QDate
    QDate newDate = QDate::fromString(date, "MM'/'dd'/'yy");
    // convert hour QString into QTime
    QString hours1 = hour.split("-")[0];
    QString hours2 = hour.split("-")[1];

    QTime newHour1 = QTime::fromString(hours1, "hh':'mm");
    QTime newHour2 = QTime::fromString(hours2, "hh':'mm");

    // Invalid date check
	if (!newDate.isValid())	
	{
        dataCout << "The date " << date << " is invalid (FORMAT: mm/dd/yy)" << endl;
		return;
	}
    //Check to see if date entered is a year in advanced
    else if (( newDate.year() < 12))
	{
        dataCout << "The year must be greater than 2012" << endl;
		return;
	}
    // Invalid hour check
    if (!newHour1.isValid()||!newHour2.isValid())
    {
        dataCout << "The hour " << hour << " is invalid (FORMAT: hh:mm-hh:mm)" << endl;
        return;
    }
    //Check to see if second time is after first time
    else if ((newHour1.operator>=(newHour2)))
    {
        dataCout << "Latter hour must be after/later than the former hour" << endl;
        return;
    }

    int posInsert = rezList.size();

    // Loop through list
    // Compares dates and hours
    for ( int i = 0; i < rezList.size(); i++)
	{
        // get the Date
        QString element = rezList[i];
		//extract just the date
        QString elemDate = element.split("-")[2];

        //extract just the room
        QString elemRoom = element.split("-")[1];

		// convert string to QDate in correct format
        QDate tmpDate = QDate::fromString(elemDate, "MM'/'dd'/'yy");

        //MAKE SURE NOT CONFLICTING TIMES!
        if (newDate.operator ==(tmpDate) && elemRoom == room)
		{
            QString elemHour1 = element.split("-")[3];
            QString elemHour2 = element.split("-")[4];
            QTime tmpHour1 = QTime::fromString(elemHour1, "hh':'mm");
            QTime tmpHour2 = QTime::fromString(elemHour2, "hh':'mm");

            if((newHour1.operator >=(tmpHour1) && newHour1.operator <=(tmpHour2)) || (newHour2.operator >=(tmpHour1) && newHour2.operator <=(tmpHour2))){
                dataCout << "Time Conflict for that room, date, and time" <<endl;
                return;
            }
		}
	}

    // insert new roomRez entry with correct index position

    QString conNum = QString::number(posInsert);

    QString newRez = conNum + "-" + room + "-" + date + "-" + hours1 + "-" + hours2;
    rezList.insert(posInsert, newRez);

    dataCout << "The roomRez entry for " << room << " has been added." <<endl << "Date: " << date << "Time: " << hours1 << "-" << hours2 << "Your confirmation number is: " << posInsert << endl;
}

//	Takes in a confirmation number and removes the reservation.

void roomRez::deleteRez(QString cNum)
{
    bool ok;
    int num = cNum.toInt(&ok, 10);
    int size = rezList.size();

    if ( num < size){
        rezList.replace(num, " - - - - ");

        dataCout << "Entry has been deleted " <<endl;
    }

}

/*	This function takes in a date from the command line.
	It should print out entries.
*/
void roomRez::printRezDate(QString dateString)
{
    dataCout << "Reservations on Date: " << dateString << endl;

    // Loop through list
    for ( int i = 0; i < rezList.size(); i++)
    {
        // get the Date
        QString element = rezList[i];
        //extract just the date
        QString tmpDate = element.split("-")[2];

        if (dateString.operator ==(tmpDate))
        {
            dataCout << formatLine(element) << endl;
        }
    }

}
void roomRez::printRezRoom(QString roomString)
{
    dataCout << "Reservations in room: " << roomString << endl;

    // Loop through list
    for ( int i = 0; i < rezList.size(); i++)
    {
        // get the room
        QString element = rezList[i];
        //extract just the room
        QString tmpRoom = element.split("-")[1];

        if (roomString.operator ==(tmpRoom))
        {
            dataCout << formatLine(element) << endl;
        }
    }
}
void roomRez::printRez()
{
    dataCout << "All Current Reservations: " << endl;

    foreach (QString str, rezList)
	{
        dataCout << formatLine(str) << endl;
	}
}

void roomRez::printHelp()
{
    dataCout << "Commands are as follows:" << endl << endl;
    dataCout << "* roomRez " << endl;
    dataCout << "(no parameters: list reservations)" << endl << endl;
    dataCout << "* roomRez -add -r room -d date -t hour " << endl;
    dataCout << "(-add: adds a new reservation) " << endl << endl;
    dataCout << "* roomRez -del confirm# " << endl;
    dataCout << "(-del: deletes an entry using the confirmation number) " << endl << endl;
    dataCout << "* roomRez -list -d date " << endl;
    dataCout << "(-list: prints room reservations for a date (-d) or room (-r))" << endl << endl;
    dataCout << "* roomRez -h " << endl;
    dataCout << "(-help: prints out help menu) " << endl << endl;
}

/*	This is a helper function which takes in a room/date/hour tripple
   as formatted within the
    saved file (rezData) and formats it to
   the correct format.
*/
QString roomRez::formatLine(QString roomDateHour)
{
    QStringList element = roomDateHour.split("-");
    QString cNum = element[0]; // Extract confirmation number
    QString room = element[1]; // Extract room
    QString date = element[2]; // Extract date
    QString hour1 = element[3]; // Extract hour1
    QString hour2 = element[4]; // Extract hour2

    if (cNum == " ")
        return " ";

	QString output;
	QTextStream os(&output);

    os << "Confirmation number: " << cNum << endl << "Room: " << room << endl << "Date: " << date <<endl
       << "Time: " << hour1 << " - " << hour2 <<endl <<endl;

	return output;
}


