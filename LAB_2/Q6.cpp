#include <iostream>
#include <string>
using namespace std;

struct Register {
    int courseId;
    string courseName;
};

struct Student : public Register {
    int studentId;
    string firstName;
    string lastName;
    string cellNo;
    string email;
};

int main() {
    const int numStudents = 5;
    Student students[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter details for student " << i + 1 << ":\n";

        cout << "Enter course ID: ";
        cin >> students[i].courseId;
        cin.ignore();

        cout << "Enter course name: ";
        getline(cin, students[i].courseName);

        cout << "Enter student ID: ";
        cin >> students[i].studentId;
        cin.ignore();

        cout << "Enter first name: ";
        getline(cin, students[i].firstName);

        cout << "Enter last name: ";
        getline(cin, students[i].lastName);

        cout << "Enter cell number: ";
        getline(cin, students[i].cellNo);

        cout << "Enter email: ";
        getline(cin, students[i].email);

        cout << endl;
    }

    cout << "\nStudent Information:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << "Student " << i + 1 << ":\n";
        cout << "Course ID: " << students[i].courseId << endl;
        cout << "Course Name: " << students[i].courseName << endl;
        cout << "Student ID: " << students[i].studentId << endl;
        cout << "First Name: " << students[i].firstName << endl;
        cout << "Last Name: " << students[i].lastName << endl;
        cout << "Cell Number: " << students[i].cellNo << endl;
        cout << "Email: " << students[i].email << endl;
        cout << endl;
    }

    return 0;
}

