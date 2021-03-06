#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Control.h"
//constructor
Control::Control()
{
  CheckInLogger* cil = new CheckInLogger();
  CheckOutLogger* col = new CheckOutLogger();

  library.subscribe(col);
  library.subscribe(cil);
}
//controls main loop for user input and output
void Control::launch()
{
  int bookId;
  int choice;

  initBooks();


  while (1)
  {
    view.showMenu(choice);

    if (choice == 0)
      break;

    view.printStr("Book id: ");
    view.readInt(bookId);

    if (choice == 1)
    {
      Book* b = library.find(bookId);

      if(b == NULL)
        cout<<"Book not found"<<endl;
      else
        library.checkOut(b);
    }
    else if (choice == 2)
    {
      Book* b = library.find(bookId);

      if(b == NULL)
        cout<<"Book not found"<<endl;
      else
        library.checkIn(b);
    }
  }

  library.print();

}
//initialize books in library
void Control::initBooks()
{
  Book* b;

  b = new Book("Ender's Game", "Card, Orson Scott");
  library.add(b);
  b = new Book("Dune", "Herbert, Frank");
  library.add(b);
  b = new Book("Foundation", "Asimov, Isaac");
  library.add(b);
  b = new Book("Hitch Hiker's Guide to the Galaxy", "Adams, Douglas");
  library.add(b);
  b = new Book("1984", "Orwell, George");
  library.add(b);
  b = new Book("Stranger in a Strange Land", "Heinlein, Robert A.");
  library.add(b);
  b = new Book("Farenheit 451", "Bradbury, Ray");
  library.add(b);
  b = new Book("2001:  A Space Odyssey", "Clarke, Arthur C.");
  library.add(b);
  b = new Book("I, Robot", "Asimov, Isaac");
  library.add(b);
  b = new Book("Starship Troopers", "Heinlein, Robert A.");
  library.add(b);
  b = new Book("Do Androids Dream of Electric Sheep?", "Dick, Philip K.");
  library.add(b);
  b = new Book("Neuromancer", "Gibson, William");
  library.add(b);
  b = new Book("Ringworld", "Niven, Larry");
  library.add(b);
  b = new Book("Rendezvous with Rama", "Clarke, Arthur C.");
  library.add(b);
  b = new Book("Hyperion", "Simmons, Dan");
  library.add(b);
}
