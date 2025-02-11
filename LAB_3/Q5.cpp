#include <iostream>

using namespace std;

class Calendar {
private:
    string months[12][31]; 
    int currentYear;

public:
    
    Calendar(int year) : currentYear(year) {
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 31; j++) {
                months[i][j] = "No Task"; 
            }
        }
    }

   
    void addTask(int month, int day, string task) {
        if (month < 1 || month > 12 || day < 1 || day > 31) {
            cout << "Invalid date!" << endl;
            return;
        }
        months[month - 1][day - 1] = task;
    }

    void removeTask(int month, int day) {
        if (month < 1 || month > 12 || day < 1 || day > 31) {
            cout << "Invalid date!" << endl;
            return;
        }
        months[month - 1][day - 1] = "No Task";
    }

    
    void showTasks() {
        cout << "Tasks for the Year " << currentYear << ":\n";
        for (int i = 0; i < 12; i++) {
            bool hasTask = false;
            for (int j = 0; j < 31; j++) {
                if (months[i][j] != "No Task") {
                    cout << "Month " << i + 1 << ", Day " << j + 1 << ": " << months[i][j] << endl;
                    hasTask = true;
                }
            }
            if (!hasTask) {
                cout << "Month " << i + 1 << ": No Tasks Assigned." << endl;
            }
        }
    }
};

int main() {
    Calendar myCalendar(2025);
    
    myCalendar.addTask(1, 5, "Doctor's Appointment");
    myCalendar.addTask(2, 14, "Valentine's Dinner");
    myCalendar.addTask(3, 10, "Project Deadline");
    myCalendar.addTask(4, 22, "Friend's Wedding");
    myCalendar.addTask(6, 5, "Family Trip");
    
    cout << "Tasks before removal:\n";
    myCalendar.showTasks();
    myCalendar.removeTask(3, 10);
    
    cout << "\nTasks after removal:\n";
    myCalendar.showTasks();
    
    return 0;
}
