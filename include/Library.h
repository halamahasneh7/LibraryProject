#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include "BookStorage.h"
#include<vector>

class Library
{
    private:
        std::vector <Book> books;

    public:
        Library();

        void addBook(const Book& book);

        bool removeBook(const std::string& ISBN);

        void displayAll()const;

        Book* searchBook(const std::string& ISBN);

        void saveToFile();

        void loadFromFile();
};
#endif // LIBRARY_H
