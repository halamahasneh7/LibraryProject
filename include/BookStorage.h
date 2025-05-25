#ifndef BOOKSTORAGE_H
#define BOOKSTORAGE_H
#include "Book.h"
#include "IBookStorage.h"
#include <vector>


class BookStorage: public IBookStorage{
    public:
        void save(const std::vector<Book>& books) override;
        void load(std::vector<Book>& books) override;
};

#endif // BOOKSTORAGE_H
