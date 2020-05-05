#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include "List.h"
#include "Logger.h"
/*
PURPOSE:
  library class holds a collection of books and updates subscribers on
books that have been checked out or checked in
*/
class Library
{
  public:
    ~Library();
    void subscribe(Logger* logger){if(logger != NULL) observers.push_back(logger);}
    void add(Book* b);
    Book* find(int id){return books.find(id);}
    void checkOut(Book* b);
    void checkIn(Book* b);
    void print();
  private:
    List books;
    vector<Logger*> observers;
    void notify(Book* b);
};

#endif
