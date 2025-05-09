#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream outFile("info.txt", ios::out);
    if (!outFile.is_open()) {
        cerr << "Error opening info.txt for writing!" << endl;
        return 1;
    }
    outFile << "C++ is a powerful programming language.";
    outFile.close();

    fstream file("info.txt", ios::in | ios::out);
    if (!file.is_open()) {
        cerr << "Error opening info.txt for reading and writing!" << endl;
        return 1;
    }

    cout << "Initial get pointer position: " << file.tellg() << endl;
    cout << "Initial put pointer position: " << file.tellp() << endl;

    file.seekg(6);
    string word;
    file >> word;
    cout << "Word at position 6: " << word << endl;

    file.seekp(6);
    file << "dynamic";

    cout << "New get pointer position: " << file.tellg() << endl;
    cout << "New put pointer position: " << file.tellp() << endl;

    file.seekg(0);
    string content;
    while (getline(file, content)) {
        cout << content << endl;
    }

    file.close();
    return 0;
}
