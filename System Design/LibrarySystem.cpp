#include<bits/stdc++.h>
using namespace std;

class Book{
    public:
    string title;
    bool isAvailable;
    Book(string t){
        title=t;
        isAvailable=true;
    }
};
class Library{
    vector<Book*>books;
    public:
    void addBook(Book *b){
        books.push_back(b);
    }
    void issueBook(string t){
        for(auto b:books){
            if(b->title==t && b->isAvailable){
                b->isAvailable=false;
                cout<<"Book is issued\n";
                return;
            }
        }
        cout<<"Book is unavailable\n";
    }
    void returnBook(string t){
        for(auto b:books){
            if(b->title==t){
                b->isAvailable=true;
                cout<<"Returned\n";
                return;
            }
        }
    }
    void showBooks(){
        cout<<"Library books: \n";
        for(auto b:books){
            cout<<b->title<<" -";
            if(b->isAvailable){
                cout<<"Available\n";
            }else{
                cout<<"Issued\n";
            }
        }
    }
};
int main(){
    Library lib;
    Book* b1=new Book("DSA");
    Book* b2=new Book("Oops");
    Book* b3=new Book("CN");
    Book* b4=new Book("DBMS");
    lib.addBook(b1);
    lib.addBook(b3);
    lib.showBooks();
    lib.issueBook("DSA");
    lib.issueBook("DBMS");
    // lib.returnBook("DSA");
    lib.showBooks();

    return 0;
}