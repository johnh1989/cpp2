#ifndef BOOKTYPE_H_INCLUDED
#define BOOKTYPE_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

class BookType{
private:
    string isbn;
    string author;
    string* authors;
    int numberOfAuthors;
    string title;
    int publishYear;
    double price;
    static int totalBooks;


public:
    BookType(){
        title = "none";
        isbn ="none";
        author = "none";
        publishYear = 0;
        price = 0.00;
    }
    ~BookType(){
        delete[] authors;
    };

    //dont need i dont think?
    void setAuthor(string a){
        author = a;
    }

    void createAuthorArray(const int index){
        authors = new string[index];
        for (int i = 0; i < index; i++){
            cout << "Enter author number " << i+1 << ": ";
            getline(cin, author);
            authors[i] = author;
        }
        numberOfAuthors = index;
    }

     void showAuthorsArray(){
        for (int i = 0; i < numberOfAuthors; i++){
            cout << i+1 << ". " <<  authors[i] << endl;
        }
    }

    int getNumberOfAuthors(){
        return numberOfAuthors;
    }

    string getAuthor(){
        return author;
    }

    void setTitle(string t){
        title = t;
    }

    string getTitle(){
        return title;
    }

    void setPublishYear(int y){
        publishYear = y;
    }

    int getPublishYear(){
        return publishYear;
    }

    void setIsbn(string i){
        isbn = i;
    }

    string getIsbn(){
        return isbn;
    }

    void setPrice(double p){
        price = p;
    }

    static void setTotalBooks(int t){
        totalBooks = t;
    }

    static int getTotalBooks(){
        return totalBooks;
    }
};


#endif // BOOKTYPE_H_INCLUDED
