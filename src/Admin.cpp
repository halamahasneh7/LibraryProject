#include "Admin.h"
#include "Library.h"
#include <iostream>

Admin::Admin(const std::string &name, const std::string &password):
    User(name,password){}

void Admin::userPermissionsList(Library &library){

        int choice;

        do{
        std::cout<<"\nWelcome Admin, Please select a choice:\n1. Add book\n2. Remove book\n3. View all books\n4. Logout or switch acount\n";

        std::cin>>choice;
        std::cin.ignore();

        switch(choice){

        case 1:
            addNewBook(library);
            break;

        case 2:
            removeBook(library);
            break;

        case 3:
            library.displayAll();
            break;

        case 4:
            std::cout<<"logout..\n";
            break;

        default:
            std::cout<<"Invalid choice. please insert a choice from 1 to 4\n";
        }
    }while(choice!=4);
    }


void Admin::addNewBook(Library &library){

    std::string title,author,isbn;
    bool availability;

    std::cin.ignore();
    std::cout<<"Enter book title\n";
    getline(std::cin,title);

     std::cout<<"Enter book author name\n";
    getline(std::cin,author);

     std::cout<<"Enter book ISBN\n";
    getline(std::cin,isbn);

     std::cout<<"Is this book available now?\nEnter 1 for Yes or 0 for No:\n";
     std::cin>>availability;

   library.addBook(Book(title,author,isbn,availability));
    }


void Admin::removeBook(Library &library){

    std::string removedISBN;
    std::cout<<"To remove a book, please enter its ISBN\n";
    std::cin.ignore();
    getline(std::cin,removedISBN);

    if(library.removeBook(removedISBN)){
        std::cout<<"Book deleted\n";
   }
    else{
        std::cout<<"Book not found\n";}
    }




