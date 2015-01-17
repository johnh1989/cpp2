#ifndef BOOKTYPE_H_INCLUDED
#define BOOKTYPE_H_INCLUDED
#include <iostream>
#include <string>
#include <algorithm>

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
    int numInStock;


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

    /* this function converts string to uppercase
        and then compares the two author strings */
    bool compareAuthor(string a){
        bool val = false;
        for (int i = 0; i < numberOfAuthors; i++){
            transform(a.begin(), a.end(), a.begin(), ::toupper);
            transform(authors[i].begin(), authors[i].end(), authors[i].begin(), ::toupper);
            if ( a == authors[i] ){
            val = true;
            }
        }
        return val;
    }

    /*converts two strings to upper and compares the ISBN's*/
    bool compareISBN(string isbn){
        bool val = false;
        int length = this->isbn.length();
        if (isbn.length() != length){
            val = false;
        }
        else{
            for (int i = 0; i < length; i++){
                transform(isbn.begin(), isbn.end(), isbn.begin(), ::toupper);
                transform(this->isbn.begin(), this->isbn.end(), this->isbn.begin(), ::toupper);
                if ( this->isbn == isbn ){
                val = true;
                }
            }
        }

        return val;
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

    double getPrice(){
        return price;
    }

    void setNumInStock(int s){
        numInStock = s;
    }

    int getNumInStock(){
        return numInStock;
    }

    static void setTotalBooks(int t){
        totalBooks = t;
    }

    static int getTotalBooks(){
        return totalBooks;
    }
};


#endif // BOOKTYPE_H_INCLUDED
