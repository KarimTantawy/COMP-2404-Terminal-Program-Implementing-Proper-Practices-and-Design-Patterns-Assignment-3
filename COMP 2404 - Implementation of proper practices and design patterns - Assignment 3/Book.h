#ifndef BOOK_H
#define BOOK_H

/*
PURPOSE:
  store information of book entity, such as title and author
*/
class Book
{
  public:
    Book(string="", string="");
    Book(Book&);
    ~Book();
    void print() const;
    static int getNextId();
    int getId();
    string getAuthor();
    bool isCheckedIn();
    void checkOut();
    void checkIn(){checkedIn = true;}

  private:
    bool checkedIn;
    static int nextId;
    int id;
    string title;
    string author;
};

#endif
