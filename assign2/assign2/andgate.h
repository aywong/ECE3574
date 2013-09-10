#ifndef ANDGATE_H
#define ANDGATE_H
#include <QString>

// Class definition of a two-input logical AND gate
class andGate {
public:
    // You may not define anything else to be public
    // You may not define anything as protected
    // The methods of this class may not print out anything other than the
    //   error messages specified below.
    //
    // init() Must be called prior to using the object
    void init();
    // Set input one (two) of this gate to be another AND gate
    void setInputOne(andGate *inputOne);
    void setInputTwo(andGate *inputTwo);
    // Set input one (two) of this gate to be tied to true or false
    //   If this is called for an input that is already set to another AND
    //   gate, then an error message should be printed out and the call should
    //   have no effect (i.e., do not change the input).
    void setInputOne(bool inputOne);
    void setInputTwo(bool inputTwo);
    // Set the name of the gate
    void setName(const QString & name);
    // Return the name of the gate
    QString getName() const;
    // Return the name of input one (two) (see main.cpp)
    QString getInputOneName() const;
    QString getInputTwoName() const;
    // Return a value that indicate the output of the gate (i.e., true or false)
    // If an input of the gate is unspecified because an input of this gate (or a gate
    //     that feeds into it) has an input that has not been set, then:
    //     (a) print out a useful warning message
    //     (b) set the unspecified input to false
    //     (c) continue execution
    bool eval() const;
private:
    // Define the private data members that you need here
};

#endif // ANDGATE_H
