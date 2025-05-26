#ifndef ADMIN_H
#define ADMIN_H
#include "User.h"

class Admin:public User{

public:
    Admin(const std::string &name, const std::string &password);

    void userPermissionsList(Library &library)override;

    void addNewBook(Library &library);

    void removeBook(Library &library);

};

#endif // ADMIN_H
