#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <vector>
using namespace std;
#include "Book.h"
#include "List.h"
/*
PURPOSE:
  Abstract class meant for subscribing and logging changes to Book classes
*/
class Logger
{
  public:
    Logger(string n="") : name(n) { }
    virtual void update(Book*) = 0;
    void printLogs();
  protected:
    string name;
    List log;
};
/*
PURPOSE:
  concrete class meant for logging every instance of book within library that
has been checked in
*/
class CheckInLogger : public Logger
{
  public:
    CheckInLogger() : Logger("Checked-in") { }
    virtual void update(Book*);
};
/*
PURPOSE:
  concrete class meant for logging every instance of book within library that
has been checked out
*/
class CheckOutLogger : public Logger
{
  public:
    CheckOutLogger() : Logger("Checked-out") { }
    virtual void update(Book*);
};

#endif
