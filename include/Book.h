#ifndef BOOK_H
#define BOOK_H
#include <string>

class Book
{
private:
    std::string m_title,m_author,m_isbn;
    bool m_availability;

public:
    Book(std::string title,std::string author,std::string isbn, bool availabilty);

    void setTitle(std::string title);
    std::string getTitle()const;


    void setAuthor(std::string author);
    std::string getAuthor()const;


    void setISBN(std::string isbn);
    std::string getISBN()const;


    void setAvailability(bool availability);
    bool isAvailable()const;

    void display()const;
};

#endif // BOOK_H
