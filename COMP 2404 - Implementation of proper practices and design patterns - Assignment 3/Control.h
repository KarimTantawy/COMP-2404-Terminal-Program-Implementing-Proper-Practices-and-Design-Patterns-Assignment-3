#ifndef CONTROL_H
#define CONTROL_H

#include "Library.h"
#include "View.h"
/*
PURPOSE:
  control flow of entire program, including launching and managing interaction
between view and entities
*/
class Control
{
  public:
    Control();
    void launch();
  private:
    Library library;
    View view;
    void initBooks();

};

#endif
