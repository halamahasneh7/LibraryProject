#ifndef MEMBER_H
#define MEMBER_H
#include "User.h"

class Member:public User{

    public:
    Member(const std::string &name, const std::string &password);

    void userPermissionsList(Library& library) override;

    void borrowBook(Library& library);

    void returnBook(Library& library);

    void searchForBook(Library& library);
};

#endif // MEMBER_H
