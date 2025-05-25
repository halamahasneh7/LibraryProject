#ifndef BOOKSTORAGE_H
#define BOOKSTORAGE_H
#include "Book.h"
#include <vector>


class BookStorage
{
    public:
       static void saveToFile(const std::vector<Book>& books);
       static void loadFromFile(std::vector<Book>& books);
};

#endif // BOOKSTORAGE_H
