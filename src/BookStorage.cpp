#include "BookStorage.h"
#include <fstream>
#include <iostream>
#include <vector>

void BookStorage::saveToFile(const std::vector<Book>& books){
    std::ofstream out("Library.txt");
    if(!out){
        std::cout<<"Can't open the file to write\n";
        return;
    }
    for(int i=0;i<books.size();i++){
        out<<books[i].getTitle()<<","<<books[i].getAuthor()<<","<<books[i].getISBN()<<","<<books[i].isAvailable()<<std::endl;
    }
    out.close();
    std::cout<<"Data saved to the file successfully."<<std::endl;
}


void BookStorage::loadFromFile(std::vector<Book>& books){

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
