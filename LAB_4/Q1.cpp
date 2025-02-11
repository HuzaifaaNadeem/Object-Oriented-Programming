#include <iostream>

using namespace std;

class Student {
private:
    int studentID;
    string name;
    int age;
    char grade;

public:
    Student() {
        studentID = 0;
        name = "";
        age = 0;
        grade = 'N';
    }

    Student(int id, string studentName, int studentAge, char studentGrade) {
        studentID = id;
        name = studentName;
        age = studentAge;
        grade = studentGrade;
    }

    void promoteStudent() {
        if (grade == 'A') {
            cout << name << " is already at the highest grade." << endl;
        } else if (grade == 'B') {
            grade = 'A';
        } else if (grade == 'C') {
            grade = 'B';
        } else if (grade == 'D') {
            grade = 'C';
        } else if (grade == 'F') {
            grade = 'D';
        }
        cout << name << " has been promoted to grade " << grade << endl;
    }

    bool isEligibleForScholarship() {
        return grade == 'A';
    }

    void displayDetails() {
        cout << "Student ID: " << studentID << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Grade: " << grade << endl;
    }

    string getName() {
        return name;
    }
};

int main() {
    Student student1(101, "Ahmed Saya", 20, 'A');
    Student student2(102, "Tariq Masood", 22, 'F');
    Student student3(103, "Shahid Anwar", 19, 'C');

    cout << "Student 1 Details:" << endl;
    student1.displayDetails();
    cout << endl;

    cout << "Student 2 Details:" << endl;
    student2.displayDetails();
    cout << endl;

    cout << "Student 3 Details:" << endl;
    student3.displayDetails();
    cout << endl;

    student1.promoteStudent();
    student1.displayDetails();
    cout << endl;

    if (student2.isEligibleForScholarship()) {
        cout << student2.getName() << " is eligible for a scholarship!" << endl;
    } else {
        cout << student2.getName() << " is not eligible for a scholarship." << endl;
    }

    return 0;
}

