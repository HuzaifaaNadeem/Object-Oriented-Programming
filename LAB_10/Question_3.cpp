#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void appendChapter(const string& sourceFile, ofstream& destFile) {
    ifstream source(sourceFile);
    if (!source.is_open()) {
        cerr << "Error opening " << sourceFile << endl;
        return;
    }

    string line;
    while (getline(source, line)) {
        destFile << line << endl;
    }
    source.close();
}

int main() {
    ofstream book("book.txt", ios::app);

    if (!book.is_open()) {
        cerr << "Error opening book.txt" << endl;
        return 1;
    }

    appendChapter("chapter1.txt", book);
    book << "\n";
    appendChapter("chapter2.txt", book);

    book.close();

    ifstream verifyBook("book.txt");
    if (!verifyBook.is_open()) {
        cerr << "Error opening book.txt for verification!" << endl;
        return 1;
    }

    cout << "Contents of book.txt:" << endl;
    string line;
    while (getline(verifyBook, line)) {
        cout << line << endl;
    }

    verifyBook.close();

    return 0;
}
