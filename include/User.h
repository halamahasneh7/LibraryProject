#ifndef USER_H
#define USER_H
#include<Library.h>

class User
{
private:
    std::string m_name,m_password;

 public:
    User(const std::string &name, const std::string &password);

    void setName(const std::string &name);
    std::string getName();

    void setPassword(const std::string &password);
    std::string getPassword();


    virtual void userPermissionsList(Library &library)=0;
    virtual ~User();
};

#endif // USER_H
