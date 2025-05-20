#include "AppController.h"
#include<iostream>

void AppController::login(User *&user,Library &library){
    while(true){
    std::string name,password;
    std::cout<<"Enter your name\n";
    std::getline(std::cin,name);

    std::cout<<"Enter your password\n";
    std::getline(std::cin,password);

    if(name=="admin" && password=="Admin123"){
        user=new Admin(name,password);
        user->userPermissionsList(library);
    }
    else if(name=="member" && password=="Member123"){
        user=new Member(name,password);
        user->userPermissionsList(library);
    }
    else{
        std::cout<<"Enter a valid name & password\n";
        continue;
        }
std::cin.ignore();
std::cout<<"Type yes to Logout or switch account \n";
std::string choice;
std::getline(std::cin,choice);

if(choice == "yes" || choice == "Yes"){
    delete user;
    user=nullptr;
    continue;
}
 else
    break;
}
}
