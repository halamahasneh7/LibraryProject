#include <iostream>
#include<Book.h>
#include<Library.h>
#include<User.h>
#include<Admin.h>
#include<Member.h>
#include<AppController.h>

int main(){
Library library1;
library1.loadFromFile();

User *user1;
AppController controller;
controller.login(user1,library1);

library1.saveToFile();

  return 0;
    }
