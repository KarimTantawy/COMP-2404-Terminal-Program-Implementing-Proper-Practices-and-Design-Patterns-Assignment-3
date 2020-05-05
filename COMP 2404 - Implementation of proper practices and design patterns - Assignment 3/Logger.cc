#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

#include "Logger.h"
#include "Book.h"
//print name and content of log
void Logger::printLogs()
{
  cout<<"LOGS "<<name<<": "<<endl;
  log.print();
}
//update if book is checkedIn and add it to collection of observer
void CheckInLogger::update(Book* b)
{
  if(b->isCheckedIn())
    log.add(b);
  else
  {
    Book* tmp = NULL;
    log.del(b->getId(), &tmp);
  }
}
//update if book is checkedOut and add it to collection of observer
void CheckOutLogger::update(Book* b)
{
  if(!b->isCheckedIn())
    log.add(b);
  else
  {
    Book* tmp = NULL;
    log.del(b->getId(), &tmp);
  }
}
