#include "User.h"

User::User(const std::string &name, const std::string &password):
    m_name(name),m_password(password){}

User::~User(){}

void User::setName(const std::string &name){m_name=name;}
std::string User::getName(){return m_name;}

void User::setPassword(const std::string &password){m_password=password;}
std::string User::getPassword(){return m_password;}

