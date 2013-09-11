#include <QDebug>
#include "andgate.h"

// Your method implementations should be in this file

/*!
  \class andGate
  \brief Representation of an AND logic gate

  1. init() Must be called prior to using the object
*/

// init() Must be called prior to using the object
void andGate::init(){
    // pointer to input one and two andGates
    this->inOne = new andGate;
    this->inTwo = new andGate;

    this->inOneBool = false;
    this->inTwoBool = false;

    // This andGate name
    this->name = "";

    // Input one and two andGate names
    this->inOneName = "";
    this->inTwoName = "";

    // TRUE if input one (two) of andGate already set to another andGate else false
    this->inOneSet = false;
    this->inTwoSet = false;
}

/*! Set input one (two) of this gate to be another AND gate */
void andGate::setInputOne(andGate *inputOne){
    Q_CHECK_PTR(inputOne);

    this->inOne = inputOne;

    if(inputOne->name.isEmpty()) qDebug() << "Entered QString is Empty";
    this->inOneName = inputOne->name;

    this->inOneSet = true;
}

void andGate::setInputTwo(andGate *inputTwo){
    Q_CHECK_PTR(inputTwo);

    this->inTwo = inputTwo;

    if(inputTwo->name.isEmpty()) qDebug() << "Entered QString is Empty";
    this->inTwoName = inputTwo->name;

    this->inTwoSet = true;
}

/*! Set input one (two) of this gate to be tied to true or false
//   If this is called for an input that is already set to another AND
//   gate, then an error message should be printed out and the call should
//   have no effect (i.e., do not change the input). */
void andGate::setInputOne(bool inputOne){
    if (this->inOneName.isEmpty()) qDebug() << "WARNING: Input One of gate  " << this->name << "  is already set to  " << this->inOneName << ": Cannot set to a boolean value";
    else{
        this->inOneBool = inputOne;
        this->inOneSet = true;
    }
}

void andGate::setInputTwo(bool inputTwo){
    if (this->inTwoName.isEmpty()) qDebug() << "WARNING: Input two of gate  " << this->name << "  is already set to  " << this->inTwoName << ": Cannot set to a boolean value";
    else{
        this->inTwoBool = inputTwo;
        this->inTwoSet = true;
    }
}

/*! Set the name of the gate */
void andGate::setName(const QString & name){
    if (name.isEmpty()) qDebug() << "Entered QString is Empty";
    this->name = name;
}

/*! Return the name of the gate */

QString andGate::getName() const
{
    if (this->name.isEmpty()) qDebug() << "String is Empty";
    return this->name;
}

/*! Return the name of input one (two) (see main.cpp)*/
QString andGate::getInputOneName() const{
    if (this->inOneName.isEmpty()) qDebug() << "String is Empty";
    return this->inOneName;
}

QString andGate::getInputTwoName() const{
    if (this->inTwoName.isEmpty()) qDebug() << "String is Empty";
    return this->inTwoName;
}

/*! Return a value that indicate the output of the gate (i.e., true or false)
// If an input of the gate is unspecified because an input of this gate (or a gate
//     that feeds into it) has an input that has not been set, then:
//     (a) print out a useful warning message
//     (b) set the unspecified input to false
//     (c) continue execution */
bool andGate::eval() const{
    if(!(this->inOneSet)) qDebug() << "WARNING: Cannot evaluate gate  " << this->name <<" : Input One is not specified.  Value returned will be meaningless.";
    if(!(this->inTwoSet)) qDebug() << "WARNING: Cannot evaluate gate  " << this->name <<" : Input Two is not specified.  Value returned will be meaningless.";

    return false;
}
