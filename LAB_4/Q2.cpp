#include <iostream>

using namespace std;

class Book {
private:
    int bookID;
    string title;
    string author;
    bool isAvailable;

public:
    Book(int id, string t, string a, bool available = true) {
        bookID = id;
        title = t;
        author = a;
        isAvailable = available;
    }

    int getBookID() const {
        return bookID;
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    bool getAvailability() const {
        return isAvailable;
    }

    void setAvailability(bool available) {
        isAvailable = available;
    }

    void display() const {
        cout << "ID: " << bookID << endl << "Title: " << title << endl 
             << "Author: " << author << endl << "Available: " 
             << (isAvailable ? "Yes" : "No") << endl << endl;
    }
};

class Library {
private:
    Book* books[100];
    int bookCount;

public:
    Library() {
        bookCount = 0;
    }

    void addBook(Book* book) {
        if (bookCount < 100) {
            books[bookCount] = book;
            bookCount++;
        } else {
            cout << "Library is full!" << endl;
        }
    }

    bool borrowBook(int id) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i]->getBookID() == id) {
                if (books[i]->getAvailability()) {
                    books[i]->setAvailability(false);
                    cout << "You borrowed: " << books[i]->getTitle() << endl<<endl;
                    return true;
                } else {
                    cout << "Sorry, this book is not available." << endl << endl;
                    return false;
                }
            }
        }
        cout << "Book not found!" << endl;
        return false;
    }

    bool returnBook(int id) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i]->getBookID() == id) {
                books[i]->setAvailability(true);
                cout << "You returned: " << books[i]->getTitle() << endl << endl;
                return true;
            }
        }
        cout << "Book not found!" << endl;
        return false;
    }

    void displayAvailableBooks() const {
        cout << "Available Books:\n\n";
        for (int i = 0; i < bookCount; i++) {
            if (books[i]->getAvailability()) {
                books[i]->display();
            }
        }
    }

    ~Library() {
        for (int i = 0; i < bookCount; i++) {
            delete books[i];
        }
    }
};

int main() {
    Library lib;

    lib.addBook(new Book(1, "1984", "George Orwell"));
    lib.addBook(new Book(2, "To Kill a Mockingbird", "Harper Lee"));
    lib.addBook(new Book(3, "The Great Gatsby", "F. Scott Fitzgerald", false));

    lib.displayAvailableBooks();

    lib.borrowBook(1);
    lib.borrowBook(3);

    lib.displayAvailableBooks();

    lib.returnBook(1);

    lib.displayAvailableBooks();

    return 0;
}

