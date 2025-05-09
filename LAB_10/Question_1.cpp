#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float gpa;
};

void write(Student s[], int n) {
    ofstream out("students.txt", ios::out);
    for (int i = 0; i < n; ++i)
        out << s[i].id << " " << s[i].name << " " << s[i].gpa << "\n";
    out.close();
}

void append(Student s) {
    ofstream out("students.txt", ios::app);
    out << s.id << " " << s.name << " " << s.gpa << "\n";
    out.close();
}

void read() {
    ifstream in("students.txt");
    Student s;
    while (in >> s.id >> s.name >> s.gpa)
        cout << s.id << " " << s.name << " " << s.gpa << endl;
    in.close();
}

int main() {
    Student s[5];
    for (int i = 0; i < 5; ++i)
        cin >> s[i].id >> s[i].name >> s[i].gpa;

    write(s, 5);

    Student extra;
    cin >> extra.id >> extra.name >> extra.gpa;
    append(extra);

    read();

    return 0;
}

