#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include "Book.h"

int Book::nextId = 1001;
//constructor
Book::Book(string t, string a) : checkedIn(true)
{
  id     = nextId;
  ++nextId;
  title  = t;
  author = a;
  //cout<<"-- default ctor:  "<< id <<endl;
}
//copy constructor
Book::Book(Book& orig)
{
  //cout<<"-- copy ctor:  "<< orig.id <<endl;

  id     = orig.id;
  title  = orig.title;
  author = orig.author;
}
//destructor
Book::~Book()
{
  //cout<<"-- dtor:  "<< id <<endl;
}
//getter for nextId
int Book::getNextId() { return nextId; }
//getter for book instance id
int Book::getId() { return id; }
//getter for author
string Book::getAuthor() { return author; }
//getter for checkedIn
bool Book::isCheckedIn() { return checkedIn; }
//change state of book's checkedIn to false
void Book::checkOut(){ checkedIn = false; }
//print all information of book
void Book::print() const
{
  string checkin = "";

  if(checkedIn)
    checkin = "Checked In";
  else
    checkin = "Checked Out";

  cout<<setw(4)<<id<<setw(37)<<title<<setw(20)<<author<<setw(15)<<checkin<<endl;
}
