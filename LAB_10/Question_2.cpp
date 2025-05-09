#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string n, e, s;
    int y;

    getline(cin, n);
    getline(cin, e);
    cin >> y;
    cin.ignore();
    getline(cin, s);

    ofstream out("resume.txt", ios::trunc);
    out << n << "\n" << e << "\n" << y << "\n" << s << "\n";
    out.close();

    ifstream in("resume.txt");
    string line;
    while (getline(in, line))
        cout << line << endl;
    in.close();

    return 0;
}
