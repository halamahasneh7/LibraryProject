#include "Book.h"
#include<iostream>

Book::Book(std::string &title,std::string &author,std::string &isbn, bool &availabilty)
:m_title(title),m_author(author),m_isbn(isbn),m_availability(availabilty){}

void Book::setTitle(std::string &title){
    if(title=="")
        std::cout<<"You must enter a book title \n";
    else
        m_title=title;
}
std::string Book::getTitle()const{
    return m_title;
    }


void Book::setAuthor(std::string &author){
    if(author=="")
        std::cout<<"You must enter an author name\n";
    else
        m_author=author;
    }
std::string Book::getAuthor()const{
    return m_author;
    }

void Book::setISBN(std::string &isbn){
    if(isbn=="")
        std::cout<<"You must enter an ISBN\n";
    else
        m_isbn=isbn;
    }
std::string Book::getISBN()const{
    return m_isbn;
    }


void Book::setAvailability(bool &availability){
   m_availability=availability;
    }
bool Book::isAvailable()const{
    return m_availability;
    }

void Book::display()const{

        if(isAvailable())
        std::cout<<"Book title is "<<getTitle()<<" and the book author is "<<getAuthor()<<" and the ISBN is "<<getISBN()
        <<" and its available"<<std::endl;

        else
            std::cout<<"Book title is "<<getTitle()<<" and the book author is "<<getAuthor()<<" and the ISBN is "<<getISBN()
        <<" and its not available"<<std::endl;
    }

