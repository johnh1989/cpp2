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

    cout << "How many books do you want to enter: ";
    cin >> numOfBooks;

    book = new BookType[numOfBooks];
    ret_index = collectData(book, numOfBooks);

    while (option != 0){
        cout << "What would you like to do next?" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Display book data" << endl;
        cout << "2. Update book data" << endl;
        cout << "3. Search by author" << endl;
        cout << "4. Search by ISBN" << endl;
        cout << " Make your selection: ";
        cin >> option;
        switch(option){
            case 0: cout << "goodbye!";
                    break;
            case 1: displayData(book, ret_index);
                    break;
            case 2: cout << "What do you want to update?" << endl;
                    cout << "1 for price" << endl;
                    cout << "2 for quantity in stock" << endl;
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
            if (publishYear < 1500 || publishYear > 2015){
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

void updateData(BookType *book, int updateOption, const int index){
    int option;
    double price;
    int qty;
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
}

void searchAuthor(BookType* book, const int index){
    string author;
    bool match = false;
    cout << "Enter Authors name: ";
    cin.ignore();
    getline(cin, author);
    for (int i = 0; i < index; i++){
        match = book[i].compareAuthor(author);
        if (match == true){
            cout << "Found: " << book[i].getTitle() << endl;
        }
    }
}

void searchISBN(BookType* book, const int index){
    cout << "place holder";
}
