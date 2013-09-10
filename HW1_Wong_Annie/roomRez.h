/*
Annie Wong
9055-27808
aywong@vt.edu
ECE3574
Homework 1
9/10/2012
*/

#ifndef roomRez_H
#define roomRez_H

#include <QDate>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include "qstd.h"

using namespace qstd;

/*
    header for roomRez.cpp
    Add/delete and list room reservations.
*/

class roomRez
{
private:
    //.dat file read and writtend to
    static QFile rezData;

    //directs this output to stdout
    static QTextStream dataCout;

    //list of entries from rezData.dat
    QStringList	rezList;

   // line formater
	QString formatLine(QString nameDateHour);
public:
	// Constructor
    roomRez();
	// Destructor
    ~roomRez();

    void addRez(QString room, QString date, QString hour);
    void deleteRez(QString confirmNum);
    void printRezDate(QString date);
    void printRezRoom(QString room);
    void printRez();
    void printHelp();
};

#endif
