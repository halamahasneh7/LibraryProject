#include <iostream>
#include "Book.h"
#include "AppController.h"
#include "BookStorage.h"


int main(){
BookStorage storge;
Library library1(&storge);
library1.loadFromFile();

AppController controller;
User* user1=nullptr;
controller.login(user1,library1);

library1.saveToFile();

delete user1;

  return 0;
    }
