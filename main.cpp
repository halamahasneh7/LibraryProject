#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;



// Book class: title & author & ISBN & Availability status
class Book{
private: //By default it's private
    string bookTitle,bookAuth,bookISBN; //ISBN String because it's not actually num it's may contain - and not used for operations
    bool availStatus;

public:
    //constructor with a default values using initialization list constructor
    Book(string title=" ", string auth=" ",string ISBN=" ", bool availability=false):
        bookTitle(title),bookAuth(auth),bookISBN(ISBN),availStatus(availability){}
    //encapsulation principles
    //set & get book title
    void setBookTitle(string title){
        bookTitle=title;
    }
    string getBookTitle()const{ //const: read only without editing and work with const objs
    return bookTitle;
    }

     //set & get book author
    void setBookAuth(string Auth){
        bookAuth=Auth;
    }
    string getBookAuth()const{
    return bookAuth;
    }

     //set & get book ISBN
       void setBookISBN(string ISBN){
        bookISBN=ISBN;
    }
    string getBookISBN()const{
    return bookISBN;
    }

    //set & get book availabilty

    void setBookAvailability(bool availability){
    availStatus=availability;
    }
    bool isAvailable()const{
    return availStatus;
    }

    //display book info
    void display()const{
        if(isAvailable())
        cout<<"Book title is "<<getBookTitle()<<" and the book author is "<<getBookAuth()<<" and the ISBN is "<<getBookISBN()
        <<" and its available"<<endl;

        else
            cout<<"Book title is "<<getBookTitle()<<" and the book author is "<<getBookAuth()<<" and the ISBN is "<<getBookISBN()
        <<" and its not available"<<endl;
    }

};

class Library{
    vector<Book> books;

    public:
        void addBook(const Book& book){
            books.push_back(book);
            cout<<"Book added."<<endl;
        }

        bool removeBook(const string& ISBN){
    for(int i=0;i< books.size();i++){
        if(books[i].getBookISBN()==ISBN){
            books.erase(books.begin()+i);
            return true; // to stop
        }
        }
        return false;
        }

        void displayAll() const{
        if(books.empty()) cout<<"You haven't add any book yet"<<endl;
        else{
        cout<<"Your book collection is:"<<endl;
    for(int i=0;i<books.size();i++){
        cout << i+1<<". ";
        books[i].display();
    }
    }
    }

        Book* searchBook(const string& ISBN){
        for(int i=0;i<books.size();i++){
            if(books[i].getBookISBN()==ISBN){
            return &books[i];
            }
        }
       return nullptr;
    }
        void saveToFile(){
    ofstream out("Library.txt");
    for(int i=0;i<books.size();i++){
        out<<books[i].getBookTitle()<<endl<<books[i].getBookAuth()<<endl<<books[i].getBookISBN()<<endl<<books[i].isAvailable()<<endl;
    }
    out.close();
    cout<<"Data saved to the file successfully."<<endl;
}
        void loadFromFile(){
ifstream in("Library.txt");
if(!in){
    cout<<"File not found"<<endl;
    return;
}
books.clear();
string title, auth, ISBN;
        bool availablitiy;
        while (getline(in, title) && getline(in, auth) && getline(in, ISBN) && in >> availablitiy) {
            in.ignore();
            books.push_back(Book(title, auth, ISBN, availablitiy));
        }
        in.close();
        cout << "Library data loaded successfully"<<endl;
    }

        ~Library(){
saveToFile();
}

};

// Must be abstract because it had a function that have a different Implementation depends on the user (admin/member)
class User{ //can't do user user1 immeditally (obj)
    public:
    User(){}//default
    //pure virtual function that make the class abstract, zero mean the the derived class should implement the function
    virtual void userPermissionsList(Library &library)=0;
    virtual ~User(){}
//    prevent memory leak, when we delete the child without this create destructor
//    it call the parent destructor and some data memory still allocal
};

class Admin:public User{
    //polymorphism override(runtime)
    void userPermissionsList(Library &library){
        int choice;
        while(true){
        cout<<"\nWelcome Admin, Please select a choice:"<<endl<<
        "1. Add book"<<endl<<"2. Remove book"<<endl<<"3. View all books"<<endl<<"4. Exit"<<endl;
        cin>>choice;
        switch(choice){
        case 1:
            addBook(library);
            break;
        case 2:
            removeBook(library);
            break;
        case 3:
            library.displayAll();
            break;
        case 4:
            cout<<"Exit"<<endl;
            return;
        default:
            cout<<"Invalid choice. please insert a choice from 1 to 4"<<endl;
        }
    }
    }
    void addBook(Library &library){

    string title,auth,ISBN;
    bool availability;

    cin.ignore();
    cout<<"Enter book title "<<endl;
    getline(cin,title);

     cout<<"Enter book author name "<<endl;
    getline(cin,auth);

     cout<<"Enter book ISBN"<<endl;
    getline(cin,ISBN);

     cout<<"Is this book available now?\nEnter 1 for Yes or 0 for No: "<<endl;
    cin>>availability;

   library.addBook(Book(title,auth,ISBN,availability));
    }

    void removeBook(Library &library){
    string removedISBN;
    cout<<"To remove a book, please enter its ISBN"<<endl;
    cin.ignore();
    getline(cin,removedISBN);
   if(library.removeBook(removedISBN)){
    cout<<"Book deleted"<<endl;
   } else{cout<<"Book not found"<<endl;}

    }


};

class Member:public User{
    void userPermissionsList(Library& library){
        int choice;
        while(true){
        cout<<"\nWelcome Member, Please select a choice: "<<endl<<"1. Borrow book"<<endl<<"2. Return borrowed book"
        <<endl<<"3. Search for a book"<<endl<<"4. Save to file"<<endl<<"5. Load from file"<<endl<<"6. Exit"<<endl;
        cin>>choice;
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
            cout<<"Exit"<<endl;
            return;
        default:
            cout<<"Invalid choice. please insert a choice from 1 to 6"<<endl;
        }
    }
      }
    void borrowBook(Library& library){
        string borrowISBN;
        cout<<"Enter Book ISBN to borrow"<<endl;
        cin.ignore();
        getline(cin,borrowISBN);
        Book* book=library.searchBook(borrowISBN);
            if(book && book->isAvailable()){
                book->setBookAvailability(0);
                cout<<"The book that holds a ISBN "<<book->getBookISBN()<<" with the title "<<book->getBookTitle()<< " Successfully borrowed."<<endl;
        }else
        cout<<"The book that holds a ISBN "<<borrowISBN<<" not available or not found."<<endl;
    }

    void returnBook(Library& library){
       string returnISBN;
        cout<<"Enter Book ISBN to return"<<endl;
        cin.ignore();
        getline(cin,returnISBN);
        Book* book=library.searchBook(returnISBN);
            if(book && !book->isAvailable()){
                book->setBookAvailability(1);
                cout<<"The book that holds a ISBN "<<book->getBookISBN()<<" Successfully retured."<<endl;
        }else
        cout<<"The book that holds a ISBN "<<returnISBN<<" already exist or not found."<<endl;
    }

    void searchForBook(Library& library){
        string isbn;
        cout<<"Enter Book ISBN you want"<<endl;
        cin.ignore();
        getline(cin,isbn);
        Book* book=library.searchBook(isbn);
        if(book) book->display();
        else cout<<"Not found"<<endl;
    }
};
int main(){
//    Book b;
//    b.setBookTitle("C++");
//    cout<<b.getBookTitle()<<endl;
//    b.display();
//    Book b1("Java", "John","75-57-855-7",true);
//    b1.display();
Library library1;
library1.loadFromFile();
User *user1;
string userType;
cout<<"Are Admin or member"<<endl;
cin>>userType;

if(userType=="Admin" || userType=="admin"){
    user1=new Admin();
}
else if(userType=="Member" || userType=="member"){
    user1=new Member();
}
else{
    cout<<"Please enter a valid choice"<<endl;
    return 0;
}
user1->userPermissionsList(library1);
delete user1;
library1.saveToFile();

    return 0;
    }
