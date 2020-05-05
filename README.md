# Terminal Program Implementing Proper Practices and Design Patterns
#### SCHOOL PROJECT - COMP 2404 - Winter 2020 Semester 
Goal of assignment was to implement 'observer' design pattern and create associated UML diagram.

##### UML Diagram:
![Image of UML](https://github.com/KarimTantawy/COMP-2404-Terminal-Program-Implementing-Proper-Practices-and-Design-Patterns-Assignment-3/blob/master/COMP%202404%20-%20Implementation%20of%20proper%20practices%20and%20design%20patterns%20-%20Assignment%203/UMLDiagram.png)

##### Submission README
Author: Kareem Tantawy

Program:
	You can check in and out books from an initialised collection. In addition, These books will be recorded in an observer class called CheckedInLogger or CheckedOutLogger which will update a collection
of books that have been checked in and checked out respectively.

Included Header Files:
1. Book.h
1. Control.h
1. Library.h
1. List.h
1. Logger.h
1. view.h
Included Source Files:
1. main.cc
1. Book.cc
1. Control.cc
1. Library.cc
1. List.cc
1. Logger.cc
1. view.cc

Instructions:
1. run makefile
    1. in terminal: make
1. makefile should produce a3 program
1. run a1 program
    1. in terminal: ./a1

Notes:
1. Everything has been implemented according to the specifications
1. Although, when compiling you might receive 2 warnings
1. On the final version of my assignment, valgrind showed that there were no memory leaks
1. The make file is the one that has been kindly provided by the TA
