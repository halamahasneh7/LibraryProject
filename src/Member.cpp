#include "Member.h"
#include<iostream>

Member::Member(const std::string &name, const std::string &password):
    User(name,password){}

void Member::userPermissionsList(Library& library){

        int choice;

        do{
        std::cout<<"\nWelcome Member, Please select a choice:\n1. Borrow book\n2. Return borrowed book\n3. Search for a book\n4. Save to file\n5. Load from file\n6. Exit\n";
        std::cin>>choice;

        switch(choice){

        case 1:
            borrowBook(library);
            break;

        case 2:
            returnBook(library);
            break;

        case 3:
            searchForBook(library);
            break;

        case 4:
            library.saveToFile();
            break;

        case 5:
            library.loadFromFile();
            break;

        case 6:
            std::cout<<"Logout or switch account\n";
            break;

        default:
            std::cout<<"Invalid choice. please insert a choice from 1 to 6\n";
        }
    }while(choice!=6);
      }


void Member::borrowBook(Library& library){
        bool availabilty;
        std::string borrowISBN;
        std::cout<<"Enter Book ISBN to borrow\n";
        std::cin.ignore();
        getline(std::cin,borrowISBN);

        Book* book=library.searchBook(borrowISBN);

            if(book && book->isAvailable()){
                availabilty=0;
                book->setAvailability(availabilty);
                std::cout<<"The book that holds a ISBN "<<book->getISBN()<<" with the title "<<book->getTitle()<< " Successfully borrowed.\n";
        }
        else
        std::cout<<"The book that holds a ISBN "<<borrowISBN<<" not available or not found.\n";
    }


void Member::returnBook(Library& library){

    bool availabilty;
    std::string returnISBN;
    std::cout<<"Enter Book ISBN to return\n";
    std::cin.ignore();
    getline(std::cin,returnISBN);

    Book* book=library.searchBook(returnISBN);

    if(book && !book->isAvailable()){
        availabilty=1;
        book->setAvailability(availabilty);
        std::cout<<"The book that holds a ISBN "<<book->getISBN()<<" Successfully retured.\n";
        }
    else
        std::cout<<"The book that holds a ISBN "<<returnISBN<<" already exist or not found.\n";
    }


void Member::searchForBook(Library& library){
        std::string isbn;
        std::cout<<"Enter Book ISBN you want\n";
        std::cin.ignore();
        getline(std::cin,isbn);

        Book* book=library.searchBook(isbn);
        if(book) book->display();
        else
            std::cout<<"Not found\n";
    }
