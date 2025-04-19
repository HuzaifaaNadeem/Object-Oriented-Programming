#include <iostream>
#include <string>
using namespace std;


class Book {
private:
    string title;
    string author;
    string isbn;

public:
    Book() {} 

    Book(const string& title, const string& author, const string& isbn)
        : title(title), author(author), isbn(isbn) {}

    string get_title() const { return title; }
    string get_author() const { return author; }
    string get_isbn() const { return isbn; }
};


class Library {
private:
    Book** books;
    int capacity;
    int book_count;

public:
    Library(int capacity = 100) {
        this->capacity = capacity;
        book_count = 0;
        books = new Book*[capacity];
    }

    ~Library() {
        for (int i = 0; i < book_count; ++i) {
            delete books[i];
        }
        delete[] books;
    }

    void add_book(const Book& book) {
        if (book_count < capacity) {
            books[book_count] = new Book(book);
            cout << "Book added: " << book.get_title() << endl;
            ++book_count;
        } else {
            cout << "Library is full.\n";
        }
    }

    void remove_book(const string& isbn) {
        for (int i = 0; i < book_count; ++i) {
            if (books[i]->get_isbn() == isbn) {
                cout << "Book removed: " << books[i]->get_title() << endl;
                delete books[i];
                for (int j = i; j < book_count - 1; ++j) {
                    books[j] = books[j + 1];
                }
                --book_count;
                return;
            }
        }
        cout << "Book with ISBN " << isbn << " not found.\n";
    }

    void search_book(const string& title) const {
        for (int i = 0; i < book_count; ++i) {
            if (books[i]->get_title() == title) {
                cout << "Book found:\n";
                cout << "Title: " << books[i]->get_title() << endl;
                cout << "Author: " << books[i]->get_author() << endl;
                cout << "ISBN: " << books[i]->get_isbn() << endl;
                return;
            }
        }
        cout << "Book titled \"" << title << "\" not found.\n";
    }
};


int main() {
    Book b1("1984", "George Orwell", "978-0451524935");
    Book b2("To Kill a Mockingbird", "Harper Lee", "978-0061120084");

    Library lib(10); 
    lib.add_book(b1);
    lib.add_book(b2);

    cout << "\nSearching for '1984':\n";
    lib.search_book("1984");

    cout << "\nRemoving book with ISBN 978-0451524935:\n";
    lib.remove_book("978-0451524935");

    cout << "\nSearching for '1984' again:\n";
    lib.search_book("1984");

    return 0;
}
