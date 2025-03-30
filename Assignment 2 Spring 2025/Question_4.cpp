#include <iostream>
#include <string>

using namespace std;

unsigned long hash_password(const string& password) {
    unsigned long hash = 5381;
    for (char c : password) {
        hash = (hash * 33) + c;
    }
    return hash;
}

class User {
protected:
    string name, email;
    int id;
    unsigned long hashed_password;
    string* permissions;
    int perm_count;

public:
    User(string name, int id, string email, string password, string perms[], int count)
        : name(name), id(id), email(email), perm_count(count) {
        hashed_password = hash_password(password);
        permissions = new string[count];
        for (int i = 0; i < count; i++) {
            permissions[i] = perms[i];
        }
    }

    virtual ~User() {
        delete[] permissions;
    }

    bool authenticate(string password) {
        return hashed_password == hash_password(password);
    }

    virtual void display() {
        cout << "Name: " << name << " | ID: " << id << " | Email: " << email << endl;
    }

    bool has_permission(string action) {
        for (int i = 0; i < perm_count; i++) {
            if (permissions[i] == action) return true;
        }
        return false;
    }

    void access_lab() {
        if (has_permission("full_lab_access")) {
            cout << name << " has full access to the lab.\n";
        } else {
            cout << name << " does not have full lab access.\n";
        }
    }
};

class Student : public User {
private:
    int* assignments;

public:
    Student(string name, int id, string email, string password)
        : User(name, id, email, password, new string[1]{"submit_assignment"}, 1) {
        assignments = new int[5]();
    }

    ~Student() {
        delete[] assignments;
    }

    void submit_assignment(int index) {
        if (index >= 0 && index < 5) {
            assignments[index] = 1;
            cout << name << " submitted assignment " << index << ".\n";
        }
    }

    void display() override {
        User::display();
    }
};

class TA : public Student {
private:
    Student** students;
    string* projects;
    int student_count;
    int project_count;

public:
    TA(string name, int id, string email, string password)
        : Student(name, id, email, password), student_count(0), project_count(0) {
        delete[] permissions;
        permissions = new string[2]{"view_projects", "manage_students"};
        students = new Student*[10];
        projects = new string[2];
    }

    ~TA() {
        delete[] students;
        delete[] projects;
    }

    void assign_student(Student* student) {
        if (student_count < 10) {
            students[student_count++] = student;
        }
    }

    void start_project(string project) {
        if (project_count < 2) {
            projects[project_count++] = project;
        }
    }

    void display() override {
        User::display();
    }
};

class Professor : public User {
public:
    Professor(string name, int id, string email, string password)
        : User(name, id, email, password, new string[2]{"assign_projects", "full_lab_access"}, 2) {}

    void assign_project(TA& ta, string project) {
        ta.start_project(project);
    }

    void display() override {
        User::display();
    }
};

void authenticateAndPerformAction(User* user, string action) {
    if (user->has_permission(action)) {
        cout << "Action \"" << action << "\" allowed for " << user->get_name() << "\n";
    } else {
        cout << "Action \"" << action << "\" denied for " << user->get_name() << "\n";
    }
}

int main() {
    Student student("Huzaifa Nadeem", 533, "huzaifa@nu.com", "pass123");
    TA ta("Ali", 102, "Ali@nu.com", "ta_pass");
    Professor professor("Dr. Abrar", 909, "Abrar@nu.com", "prof_pass");

    student.display();
    ta.display();
    professor.display();

    authenticateAndPerformAction(&student, "submit_assignment");
    authenticateAndPerformAction(&ta, "manage_students");
    authenticateAndPerformAction(&professor, "full_lab_access");

    student.submit_assignment(2);
    ta.assign_student(&student);
    professor.assign_project(ta, "AI Research");
    
    return 0;
}
