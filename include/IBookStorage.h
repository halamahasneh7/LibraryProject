#ifndef IBOOKSTORAGE_H
#define IBOOKSTORAGE_H
#include "Book.h"
#include <vector>


class IBookStorage
{
    public:
       virtual void save(const std::vector<Book>& books)=0;
       virtual void load(std::vector<Book>& books)=0;
        virtual ~IBookStorage();
};

#endif // IBOOKSTORAGE_H
