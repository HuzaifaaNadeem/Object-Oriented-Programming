#include <iostream>
using namespace std;

class Employee {
private:
    int id;
    string name;
    string department;
    double salary;

public:
    Employee() : id(0), name(""), department(""), salary(0.0) {}

    Employee(int empID, string empName, string dept, double empSalary) 
        : id(empID), name(empName), department(dept), salary(empSalary) {}

    void giveBonus(double amount) {
        salary += amount;
    }

    bool isManager() {
        return department == "Management";
    }

    void display() const {
        cout << "ID: " << id << " | Name: " << name << " | Department: " << department << " | Salary: $" << salary << endl;
    }
    
    string getname() const{
	   return name;
	}
};

int main() {
    Employee emp1(101, "Huzaifa Nadeem", "Management", 50000.0);
    Employee emp2(102, "Burair Hyder", "Engineering", 40000.0);
    Employee emp3(103, "Najam Nasr", "Marketing", 35000.0);

    emp1.display();
    emp2.display();
    emp3.display();

    emp1.giveBonus(5000.0);
    emp2.giveBonus(3000.0);
    emp3.giveBonus(2000.0);

    emp1.display();
    emp2.display();
    emp3.display();

    cout << "Is "<< emp1.getname()<<" a manager?" << endl << (emp1.isManager() ? "Yes" : "No") << endl;
    cout << "Is "<< emp2.getname()<<" a manager?" << endl  << (emp2.isManager() ? "Yes" : "No") << endl;
    cout << "Is "<< emp3.getname()<<" a manager?" << endl  << (emp3.isManager() ? "Yes" : "No") << endl;

    return 0;
}

