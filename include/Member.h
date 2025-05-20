#ifndef MEMBER_H
#define MEMBER_H
#include<Library.h>
#include<Book.h>
#include<User.h>

class Member:public User{

    private:
    void userPermissionsList(Library& library)override;

    public:
    Member(const std::string &name, const std::string &password);

    void borrowBook(Library& library);

    void returnBook(Library& library);

    void searchForBook(Library& library);
};

#endif // MEMBER_H
