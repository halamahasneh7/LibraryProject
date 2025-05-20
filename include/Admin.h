#ifndef ADMIN_H
#define ADMIN_H
#include<Library.h>
#include<User.h>

class Admin:public User{
private:
    void userPermissionsList(Library &library)override;

public:
    Admin(const std::string &name, const std::string &password);

    void addNewBook(Library &library);

    void removeBook(Library &library);

};

#endif // ADMIN_H
