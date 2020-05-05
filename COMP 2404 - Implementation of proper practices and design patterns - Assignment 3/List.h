#ifndef LIST_H
#define LIST_H

#include "Book.h"
/*
PURPOSE:
  collection class that holds and manipulates collection of Book classes
*/
class List
{
  class Node
  {
    public:
      Book* data;
      Node* next;
  };

  public:
    List();
    ~List();
    void add(Book*);
    void del(int, Book**);
    void cleanup();
    Book* find(int);
    void print() const;

  private:
    Node* head;
};

#endif
