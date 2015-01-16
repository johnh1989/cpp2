#include <iostream>
#include <booktype.h>

using namespace std;

int collectData(BookType*, const int);

int BookType::totalBooks = 0;

int main()
{
    BookType* book;
    int  numOfBooks;
    int ret_index;

    cout << "How many books do you want to enter: ";
    cin >> numOfBooks;

    book = new BookType[numOfBooks];
    ret_index = collectData(book, numOfBooks);
    cout << ret_index;

    return 0;
}


int collectData(BookType* book, const int index){
    string title;
    string isbn;
    char addBook = 'Y';
    int numOfAuthors;
    int publishYear;
    double price;

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
            book[i].setPublishYear(publishYear);

            cout << "Enter price for " << book[i].getTitle() << ": ";
            cin >> price;
            book[i].setPrice(price);

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
