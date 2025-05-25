#include "Library.h"
#include "BookStorage.h"
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
   BookStorage::saveToFile(books);
}


void Library::loadFromFile(){

  BookStorage::loadFromFile(books);
    }


