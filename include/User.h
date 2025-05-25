#ifndef USER_H
#define USER_H
#include "Library.h"

class User{
protected:
    std::string m_name,m_password;

 public:
    User(const std::string &name, const std::string &password);
    virtual void userPermissionsList(Library &library)=0;
    virtual ~User();
};
#endif // USER_H
