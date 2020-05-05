#include <iostream>
using namespace std;

#include "List.h"
//constructor
List::List() : head(NULL) { }
//destructor
List::~List()
{
  Node* currNode;
  Node* nextNode;

  currNode = head;
  //remove nodes without deallocating data
  while (currNode != NULL) {
    nextNode = currNode->next;
    delete currNode;
    currNode = nextNode;
  }
}
//deallocated data of book without deallocating nodes
void List::cleanup()
{
  Node* currNode;

  currNode = head;

  while (currNode != NULL)
  {
    Book* tmpData = currNode->data;
    currNode = currNode->next;
    delete tmpData;
  }
}
//find book by id
Book* List::find(int id)
{
  Book* tmpBook = NULL;
  Node* currNode;

  currNode = head;

  while (currNode != NULL)
  {
    if (id == currNode->data->getId())
      tmpBook = currNode->data;

    currNode = currNode->next;
  }

  return tmpBook;
}
//add book that doesn't exist in the collection, in alphabetical order
void List::add(Book* book)
{
  Node* tmpNode;
  Node* currNode;
  Node* prevNode;

  tmpNode = new Node;
  tmpNode->data = book;
  tmpNode->next = NULL;

  prevNode = NULL;
  currNode = head;

  while (currNode != NULL)
  {
    if(book == currNode->data)
      return;

    if (book->getAuthor() < currNode->data->getAuthor())
      break;

    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == NULL)
    head = tmpNode;
  else
    prevNode->next = tmpNode;

  tmpNode->next  = currNode;

}
//remove Book instance pointer from collection and return it to user
void List::del(int id, Book** book)
{
  Node* currNode;
  Node* prevNode;

  currNode = head;
  prevNode = NULL;

  while (currNode != NULL) {
    if (currNode->data->getId() == id)
      break;

    prevNode = currNode;
    currNode = currNode->next;
  }

// we get here if we didn't find the name or if we did find the name
  if (currNode == NULL) {
    *book = NULL;
    return;
  }

  if (prevNode == NULL)
    head = currNode->next;
  else
    prevNode->next = currNode->next;

  *book = currNode->data;
  delete currNode;
}
//print contents of collection
void List::print() const
{
  Node* currNode = head;

  while (currNode != NULL) {
    currNode->data->print();
    currNode = currNode->next;
  }
}
