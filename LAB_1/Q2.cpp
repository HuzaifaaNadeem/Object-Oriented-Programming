#include <iostream>
using namespace std;

struct Student {
    int rollNumber;
    int mathMarks;
    int englishMarks;
    int scienceMarks;
    int totalMarks;
    double averageMarks;
    char grade;
};

int main() {
    int TotalStudents;

    cout << "Enter the number of students: ";
    cin >> TotalStudents;

    Student students[TotalStudents];

    for (int i = 0; i < TotalStudents; ++i) {
        cout << endl << "Enter roll number of student " << i + 1 << ": ";
        cin >> students[i].rollNumber;

        cout << "Enter marks for Mathematics: ";
        cin >> students[i].mathMarks;

        cout << "Enter marks for English: ";
        cin >> students[i].englishMarks;

        cout << "Enter marks for Science: ";
        cin >> students[i].scienceMarks;

        students[i].totalMarks = students[i].mathMarks + students[i].englishMarks + students[i].scienceMarks;
        students[i].averageMarks = students[i].totalMarks / 3.0;

        if (students[i].averageMarks >= 90) {
            students[i].grade = 'A';
        } else if (students[i].averageMarks >= 80) {
            students[i].grade = 'B';
        } else if (students[i].averageMarks >= 70) {
            students[i].grade = 'C';
        } else if (students[i].averageMarks >= 60) {
            students[i].grade = 'D';
        } else {
            students[i].grade = 'F';
        }
    }

    for (int i = 0; i < TotalStudents; ++i) {
        cout << endl << "Results for Student " << students[i].rollNumber << ":" << endl;
        cout << "Mathematics: " << students[i].mathMarks << endl;
        cout << "English: " << students[i].englishMarks << endl;
        cout << "Science: " << students[i].scienceMarks << endl;
        cout << "Total Marks: " << students[i].totalMarks << endl;
        cout << "Average Marks: " << students[i].averageMarks << endl;
        cout << "Grade: " << students[i].grade << endl;
    }

    return 0;
}
