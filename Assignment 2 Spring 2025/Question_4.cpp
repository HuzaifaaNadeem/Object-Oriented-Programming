#include <iostream>
using namespace std;

class User;

string hashPassword(string plainPassword) {
    int hash = 5381;
    for (int i = 0; i < plainPassword.length(); i++) {
        hash = hash * 33 + plainPassword[i];
    }
    return to_string(hash);
}

class User {
protected:
    string userName;
    string userId;
    string* accessPermissions;
    int permissionCount;
    int maxPermissions;
    string emailAddress;
    string passwordHash;

public:
    User(string name, string id, int permissionLimit, string email, string hashedPassword) {
        userName = name;
        userId = id;
        maxPermissions = permissionLimit;
        accessPermissions = new string[maxPermissions];
        emailAddress = email;
        passwordHash = hashedPassword;
        permissionCount = 0;
    }

    User() {}

    bool authenticate(string inputPassword) {
        string tempHash = hashPassword(inputPassword);
        return (tempHash == passwordHash);
    }

    void addPermission(string permission) {
        if (permissionCount < maxPermissions) {
            accessPermissions[permissionCount] = permission;
            permissionCount++;
        }
    }

    virtual void displayInfo() {
        cout << "Displaying User Info:\n";
        cout << "Name: " << userName << "\n";
        cout << "ID: " << userId << "\n";
        cout << "Permissions:\n";
        for (int i = 0; i < permissionCount; i++) {
            cout << "  " << i + 1 << ". " << accessPermissions[i] << "\n";
        }
        cout << "Email: " << emailAddress << "\n";
    }

    string getName() {
        return userName;
    }

    bool hasLabAccess() {
        for (int i = 0; i < permissionCount; i++) {
            if (accessPermissions[i] == "full_lab_access") {
                return true;
            }
        }
        return false;
    }

    virtual bool checkPermission(string action) {
        for (int i = 0; i < permissionCount; i++) {
            if (accessPermissions[i] == action) {
                return true;
            }
        }
        return false;
    }
};

void authenticateAndPerformAction(User* currentUser, string action) {
    string password;
    cout << "Enter Password: ";
    cin >> password;

    if (currentUser->authenticate(password)) {
        cout << "Authentication successful!\n";

        if (currentUser->checkPermission(action)) {
            cout << "Permission granted for action: " << action << "\n";

            if (action == "view_projects") {
                cout << currentUser->getName() << " is viewing projects.\n";
            } else if (action == "manage_students") {
                cout << currentUser->getName() << " is managing students.\n";
            } else {
                cout << "Unknown action: " << action << "\n";
            }
        } else {
            cout << "Permission denied for action: " << action << "\n";
        }
    } else {
        cout << "Invalid password!\n";
    }
}

class Student : public User {
private:
    int* assignmentStatus;
    int maxAssignments;
    int completedAssignments;

public:
    Student(string name, string id, int permissionLimit, string email, string hashedPass, int assignmentLimit)
        : User(name, id, permissionLimit, email, hashedPass) {
        maxAssignments = assignmentLimit;
        assignmentStatus = new int[maxAssignments];
        addPermission("submit_assignment");
        completedAssignments = 0;

        for (int i = 0; i < maxAssignments; i++) {
            assignmentStatus[i] = 0;
        }
    }

    Student() {}

    void displayInfo() override {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        User::displayInfo();
        cout << "Pending Assignments:\n";
        for (int i = 0; i < maxAssignments; i++) {
            if (assignmentStatus[i] != 1) {
                cout << "  Assignment No." << i + 1 << "\n";
            }
        }
        cout << "Completed Assignments:\n";
        for (int i = 0; i < maxAssignments; i++) {
            if (assignmentStatus[i] != 0) {
                cout << "  Assignment No." << i + 1 << "\n";
            }
        }
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    }

    void addAssignment() {
        if (completedAssignments < maxAssignments) {
            assignmentStatus[completedAssignments] = 0;
            completedAssignments++;
        } else {
            cout << "Max Assignment Limit Reached!\n";
        }
    }

    void completeAssignment(int index) {
        assignmentStatus[index - 1] = 1;
        cout << "Assignment No." << index << " marked as completed!\n";
        completedAssignments--;
    }
};

class TA : public Student {
private:
    Student* assignedStudents;
    int studentLimit;
    int studentCount;
    string* projectList;
    int maxProjects;
    int currentProjects;

public:
    TA(string name, string id, int permissionLimit, string email, string hashedPass, int assignmentLimit)
        : Student(name, id, permissionLimit, email, hashedPass, assignmentLimit) {
        studentLimit = 10;
        assignedStudents = new Student[studentLimit];
        maxProjects = 2;
        projectList = new string[maxProjects];
        studentCount = 0;
        currentProjects = 0;

        addPermission("manage_students");
        addPermission("view_projects");
    }

    TA() {
        studentLimit = 10;
        assignedStudents = new Student[studentLimit];
        maxProjects = 2;
        projectList = new string[maxProjects];
        studentCount = 0;
        currentProjects = 0;
    }

    void displayInfo() override {
        Student::displayInfo();
        cout << "Assigned Students:\n";
        for (int i = 0; i < studentCount; i++) {
            cout << assignedStudents[i].getName() << "\n";
        }
        cout << "Ongoing Projects:\n";
        for (int i = 0; i < currentProjects; i++) {
            cout << "  Project " << i + 1 << ": " << projectList[i] << "\n";
        }
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    }

    bool addProject(string newProject) {
        if (currentProjects < maxProjects) {
            projectList[currentProjects] = newProject;
            currentProjects++;
            cout << "Project: " << newProject << " successfully added\n";
            return true;
        } else {
            cout << "Max project limit reached!\n";
            return false;
        }
    }

    bool addStudent(Student s) {
        if (checkPermission("manage_students")) {
            if (studentCount < studentLimit) {
                assignedStudents[studentCount] = s;
                studentCount++;
                return true;
            } else {
                cout << "Max student limit reached!\n";
                return false;
            }
        }
        cout << "You don't have permission to manage students!\n";
        return false;
    }

    int getProjectCount() {
        return currentProjects;
    }
};

class Professor : public User {
private:
    TA* teachingAssistants;
    int totalTAs;
    int maxTAs;

public:
    Professor(string name, string id, int permissionLimit, string email, string hashedPass, int taLimit)
        : User(name, id, permissionLimit, email, hashedPass) {
        addPermission("assign_projects");
        addPermission("full_lab_access");
        teachingAssistants = new TA[taLimit];
        maxTAs = taLimit;
        totalTAs = 0;
    }

    void assignTA(TA assistant) {
        if (totalTAs < maxTAs) {
            teachingAssistants[totalTAs] = assistant;
            totalTAs++;
        } else {
            cout << "Cannot assign more TAs!\n";
        }
    }

    void workWithTA(string projectName) {
        if (totalTAs == 0) {
            cout << "No TA assigned. Cannot assign projects.\n";
            return;
        }

        bool assigned = false;
        for (int i = 0; i < totalTAs; i++) {
            if (teachingAssistants[i].getProjectCount() < 2) {
                teachingAssistants[i].addProject(projectName);
                cout << "Professor " << getName() << " is working with TA " << teachingAssistants[i].getName()
                     << " on project: " << projectName << "\n";
                assigned = true;
                break;
            }
        }

        if (!assigned) {
            cout << "All TAs have reached their project limit.\n";
        }
    }

    void displayInfo() override {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        User::displayInfo();
        cout << "Assigned TAs:\n";
        if (totalTAs == 0) {
            cout << "No TAs assigned yet!\n";
        } else {
            for (int i = 0; i < totalTAs; i++) {
                cout << "  " << i + 1 << ". Name: " << teachingAssistants[i].getName() << "\n";
            }
        }
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    }
};

int main() {
	cout << "Huzaifa Nadeem"<<endl;
    cout << "24K-0533"<<endl;
    cout << "BCS-2F"<<endl<<endl;
	
    Professor drAli("Dr. Ali", "P001", 5, "dr.ali@university.edu", hashPassword("prof123"), 2);

    TA taSarah("Sarah", "TA101", 5, "sarah@university.edu", hashPassword("ta123"), 5);
    TA taHamza("Hamza", "TA102", 5, "hamza@university.edu", hashPassword("ta456"), 5);

    Student studentAhsan("Ahsan", "S001", 3, "ahsan@student.edu", hashPassword("student123"), 5);
    Student studentMira("Mira", "S002", 3, "mira@student.edu", hashPassword("student456"), 5);

    drAli.assignTA(taSarah);
    drAli.assignTA(taHamza);

    taSarah.addStudent(studentAhsan);
    taSarah.addStudent(studentMira);

    studentAhsan.addAssignment();
    studentAhsan.addAssignment();
    studentMira.addAssignment();

    studentAhsan.completeAssignment(1);
    studentAhsan.completeAssignment(2);
    studentMira.completeAssignment(1);

    taSarah.addProject("AI-Based Grading System");
    taHamza.addProject("Cloud-Based Attendance");

    drAli.workWithTA("Machine Learning Research");

    cout << "\n--- Professor Info ---\n";
    drAli.displayInfo();

    cout << "\n--- TA Info ---\n";
    taSarah.displayInfo();
    taHamza.displayInfo();

    cout << "\n--- Student Info ---\n";
    studentAhsan.displayInfo();
    studentMira.displayInfo();

    string userInputPassword;
    cout << "\nEnter password for student Ahsan: ";
    cin >> userInputPassword;

    if (studentAhsan.authenticate(userInputPassword)) {
        cout << "Authentication successful!\n";
    } else {
        cout << "Invalid password!\n";
    }

    authenticateAndPerformAction(&taSarah, "manage_students");

    return 0;
}
