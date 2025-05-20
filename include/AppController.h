#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H
#include "User.h"
#include "Library.h"
#include "Admin.h"
#include "Member.h"


class AppController
{
    public:
    void login(User *&user,Library &libraary);
};

#endif // APPCONTROLLER_H
