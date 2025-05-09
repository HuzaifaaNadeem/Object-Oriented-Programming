#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream outFile("data.txt", ios::out);
    outFile << "AI is the future. AI will transform the world. Embrace AI now.";
    outFile.close();

    string search, replace;
    cout << "Enter the search word: ";
    cin >> search;
    cout << "Enter the replacement word: ";
    cin >> replace;

    fstream file("data.txt", ios::in | ios::out);
    if (!file.is_open()) {
        cerr << "Error opening data.txt!" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        size_t pos = 0;
        while ((pos = line.find(search, pos)) != string::npos) {
            streampos currPos = file.tellg();
            file.seekp(currPos);
            file << replace;

            size_t diff = replace.length() < search.length() ? search.length() - replace.length() : 0;
            for (size_t i = 0; i < diff; ++i) {
                file.put(' ');
            }
            pos += replace.length();
        }
    }

    file.close();

    ifstream updatedFile("data.txt");
    cout << "Updated content:" << endl;
    string updatedLine;
    while (getline(updatedFile, updatedLine)) {
        cout << updatedLine << endl;
    }

    updatedFile.close();
    return 0;
}
