#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Library.h"

//destructor
Library::~Library()
{
  //print();

  //cout<<endl;
  //deallocate each logger class
  for(int i=observers.size()-1; i>=0; i--)
  {
    observers[i]->printLogs();
    delete observers[i];
  }
  //dealocate each book
  books.cleanup();
}
//notify observers, by updating them individually with book that has been updated
void Library::notify(Book* b)
{
  for(int i=0; i < observers.size(); i++)
  {
    observers[i]->update(b);
  }
}
//add book to library
void Library::add(Book* b)
{
  books.add(b);
  notify(b);
}
//checkout book and notify observers appropriately
void Library::checkOut(Book* b)
{
  Book* tmp = books.find(b->getId());

  if(tmp == NULL)
    return;

  tmp->checkOut();

  notify(tmp);
}
//check in book and notify observers appropriately
void Library::checkIn(Book* b)
{
  Book* tmp = books.find(b->getId());

  if(tmp == NULL)
    return;

  tmp->checkIn();

  notify(tmp);
}
//print books in library
void Library::print()
{
  cout<<"Library: "<<endl;
  books.print();
}
