/*John H.
This program allows a user to enter information for desired amount of books,
including, price, publish date, up to 4 authors, and ISBN
*/

#include <iostream>
#include <booktype.h>

using namespace std;

int collectData(BookType*, const int);
void displayData(BookType*, const int);
void updateData(BookType*, int, const int);
void searchAuthor(BookType*, const int);
void searchISBN(BookType*, const int);

int BookType::totalBooks = 0;

int main()
{
    BookType* book;
    int  numOfBooks;
    int ret_index;
    int option = 1;
    int updateOption;
    char keepGoing;

    cout << "How many books do you want to enter: ";
    cin >> numOfBooks;
    while(numOfBooks <= 0){
        cout << "Do you want to exit y/n: ";
        cin >> keepGoing;
        keepGoing = toupper(keepGoing);
        if (keepGoing == 'N'){
            cout << "Please enter at least one book: ";
            cin >> numOfBooks;
        }
        else{
            cout << "\nGoodbye!";
            return 0;
        }
    }

    book = new BookType[numOfBooks];
    ret_index = collectData(book, numOfBooks);

    while (option != 0){
        cout << "\nWhat would you like to do next?" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Display book data" << endl;
        cout << "2. Update book data" << endl;
        cout << "3. Search by author" << endl;
        cout << "4. Search by ISBN" << endl;
        cout << " MAKE YOUR SELECTION > ";
        cin >> option;
        switch(option){
            case 0: cout << "goodbye!";
                    break;
            case 1: displayData(book, ret_index);
                    break;
            case 2: cout << "What do you want to update?" << endl;
                    cout << "1 for price" << endl;
                    cout << "2 for quantity in stock" << endl;
                    cout << "3 for authors" << endl;
                    cout << "4 for publish year" << endl;
                    cout << "5 for title" << endl;
                    cin >> updateOption;
                    updateData(book, updateOption, ret_index);
                    break;
            case 3: searchAuthor(book, ret_index);
                    break;
            case 4: searchISBN(book, ret_index);
                    break;
        }
    }
    return 0;
}

int collectData(BookType* book, const int index){
    string title;
    string isbn;
    char addBook = 'Y';
    int numOfAuthors;
    int publishYear;
    double price;
    int numInStock;

    for (int i = 0; i < index; i++){
        if (addBook != 'N'){
            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, title);
            book[i].setTitle(title);

            cout << "How many authors does " << book[i].getTitle() << " have: ";
            cin >> numOfAuthors;
            cin.ignore();
            book[i].createAuthorArray(numOfAuthors);
            //book[i].showAuthorsArray();

            cout << "Enter ISBN for " << book[i].getTitle() << ": ";
            cin >> isbn;
            book[i].setIsbn(isbn);

            cout << "Enter publisher year for " << book[i].getTitle() << ": ";
            cin >> publishYear;
            while(publishYear < 1500 || publishYear > 2015){
                cout << "Please enter a valid year: ";
                cin >> publishYear;
            }
            book[i].setPublishYear(publishYear);

            cout << "Enter price for " << book[i].getTitle() << ": ";
            cin >> price;
            book[i].setPrice(price);

            cout << "Enter number in stock: ";
            cin >> numInStock;
            book[i].setNumInStock(numInStock);

            BookType::setTotalBooks(i+1);

            if(BookType::getTotalBooks() == 10){
                cout << "Maximum of ten books has been reached" << endl;
                return BookType::getTotalBooks();
            }

            if (BookType::getTotalBooks() < index){
                cout << "Add another book? y/n"; // give them the option to exit
                cin >> addBook;
                addBook = toupper(addBook);
            }


        }
    }
    return BookType::getTotalBooks();
}

void displayData(BookType* book, const int index){
    for (int i = 0; i < index; i++){
        cout << "\nTitle: " << book[i].getTitle() << endl;
        cout << "Authors: " << endl;
        cout << "---------" << endl;
        book[i].showAuthorsArray();
        cout << "---------" << endl;
        cout << "ISBN #: " << book[i].getIsbn() << endl;
        cout << "Publisher Year: " << book[i].getPublishYear() << endl;
        cout << "Price: " << book[i].getPrice() << endl;
        cout << "Stock QTY: " << book[i].getNumInStock() << endl;
    }
}

/*update either price or QTY in stock based on integer option from main().*/
void updateData(BookType *book, int updateOption, const int index){
    int option;
    double price;
    string title;
    int qty;
    int numOfAuthors;
    int year;
    if (updateOption == 1){
        cout << "Which book do you want to update the price for?" << endl;
        for (int i = 0; i < index; i++){
            cout << i+1 << ". " << book[i].getTitle() << endl;
        }
        cin >> option;
        cout << "Enter price for " << book[option-1].getTitle() << ": ";
        cin >> price;
        book[option-1].setPrice(price);
    }
    if ( updateOption == 2){
        cout << "Which book do you want to update quantity in stock for?" << endl;
        for (int i = 0; i < index; i++){
            cout << i+1 << ". " << book[i].getTitle() << endl;
        }
        cin >> option;
        cout << "Enter Stock QTY for " << book[option-1].getTitle() << ": ";
        cin >> qty;
        book[option-1].setNumInStock(qty);
    }
    if (updateOption == 3){
        cout << "Which book do you want to update the authors for?" << endl;
        for (int i = 0; i < index; i++){
            cout << i+1 << ". " << book[i].getTitle() << endl;
        }
        cin >> option;
        cout << "How many authors does " << book[option-1].getTitle() << " have: ";
        cin >> numOfAuthors;
        cin.ignore();
        book[option-1].createAuthorArray(numOfAuthors);
    }
    if (updateOption == 4){
        cout << "Which book do you want to update the publish year for?" << endl;
        for (int i = 0; i < index; i++){
            cout << i+1 << ". " << book[i].getTitle() << endl;
        }
        cin >> option;
        cout << "Enter enter new publish year for " << book[option-1].getTitle() << ": ";
        cin >> year;
        book[option-1].setPublishYear(year);
    }
    if (updateOption == 5){
        cout << "Which book do you want to update the title for?" << endl;
        for (int i = 0; i < index; i++){
            cout << i+1 << ". " << book[i].getTitle() << endl;
        }
        cin >> option;
        cout << "Enter enter new title for " << book[option-1].getTitle() << ": ";
        cin >> title;
        book[option-1].setTitle(title);
    }
}

/* User enters name here and then BookType member function searches for a match*/
void searchAuthor(BookType* book, const int index){
    string author;
    bool match = false;
    cout << "Enter Authors name: ";
    cin.ignore();
    getline(cin, author);
    for (int i = 0; i < index; i++){
        match = book[i].compareAuthor(author);
        if (match == true){
            cout << "\nFound: " << book[i].getTitle() << "\n" << endl;
        }
    }
}

/* User enters ISBN here and then BookType member function searches for a match*/
void searchISBN(BookType* book, const int index){
    string isbn;
    bool match = false;
    cout << "Enter ISBN: ";
    cin.ignore();
    getline(cin, isbn);
    for (int i = 0; i < index; i++){
        match = book[i].compareISBN(isbn);
        if (match == true){
            cout << "Found: " << book[i].getTitle() << "\n" << endl;
        }
        else{
            cout << "\nNONE FOUND\n" << endl;
        }
    }
}
