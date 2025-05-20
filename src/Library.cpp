#include "Library.h"
#include<fstream>
#include<iostream>

Library::Library(){}


void Library::addBook(const Book& book){
        books.push_back(book);
        std::cout<<"Book added."<<std::endl;
    }


bool Library::removeBook(const std::string& isbn){
        for(int i=0;i< books.size();i++){
            if(books[i].getISBN()==isbn){
                books.erase(books.begin()+i);
            return true;
            }
        }
            return false;
    }


void Library::displayAll() const{
    if(books.empty()) std::cout<<"You haven't add any book yet"<<std::endl;
        else{
            std::cout<<"Your book collection is:"<<std::endl;

        for(int i=0;i<books.size();i++){
                std::cout << i+1<<". ";
                books[i].display();
                }
            }
        }


Book* Library::searchBook(const std::string& isbn){
    for(int i=0;i<books.size();i++){
        if(books[i].getISBN()==isbn){
            return &books[i];
            }
        }
       return nullptr;
    }


void Library::saveToFile(){
    std::ofstream out("Library.txt");
    for(int i=0;i<books.size();i++){
        out<<books[i].getTitle()<<","<<books[i].getAuthor()<<","<<books[i].getISBN()<<","<<books[i].isAvailable()<<std::endl;
    }
    out.close();
    std::cout<<"Data saved to the file successfully."<<std::endl;
}


void Library::loadFromFile(){

    std::ifstream in("Library.txt");

        if(!in){
            std::cout<<"File not found"<<std::endl;
            return;
        }

        books.clear();

        std::string title, author, isbn;
        bool availablitiy;

        while (std::getline(in, title,',') && std::getline(in, author,',') && std::getline(in, isbn,',') && in>>availablitiy) {
            in.ignore();
            books.push_back(Book(title, author, isbn, availablitiy));
        }
        in.close();
        std::cout << "Library data loaded successfully"<<std::endl;
    }


