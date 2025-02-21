#include <iostream>
#include <string>
using namespace std;

const int MAX_SKILLS = 10;
const int MAX_SPORTS = 5;
const int MAX_LEARNERS = 10;

class Skill {
private:
    int skill_id;
    string skill_name;
    string description;

public:
    Skill(int id = 0, string name = "", string desc = "") : skill_id(id), skill_name(name), description(desc) {}
    
    int getSkillId() const { return skill_id; }
    string getSkillName() const { return skill_name; }
    string getDescription() const { return description; }
    void setDescription(const string& new_description) { description = new_description; }

    void showSkillDetails() const {
        cout << "Skill ID: " << skill_id << ", Name: " << skill_name << ", Description: " << description << endl;
    }

    void updateSkillDescription(const string& new_description) {
    description = new_description;
    cout << "Skill description updated successfully.\n";
}
};

class Sport {
private:
    int sport_id;
    string name;
    string description;
    Skill required_skills[MAX_SKILLS];
    int skill_count;

public:
    Sport(int id = 0, string sport_name = "", string desc = "") : sport_id(id), name(sport_name), description(desc), skill_count(0) {}
    
    int getSportId() const { return sport_id; }
    string getName() const { return name; }
    string getDescription() const { return description; }
    void setDescription(const string& desc) { description = desc; }
    
    void addSkill(const Skill& skill) {
        if (skill_count < MAX_SKILLS) {
            required_skills[skill_count++] = skill;
        }
    }

    bool removeSkill(int skill_id) {
    for (int i = 0; i < skill_count; i++) {
        if (required_skills[i].getSkillId() == skill_id) {
            for (int j = i; j < skill_count - 1; j++) {
                required_skills[j] = required_skills[j + 1];
            }
            skill_count--;
            cout << "Skill removed from sport: " << name << endl;
            return true;
        }
    }
    cout << "Skill ID not found in this sport.\n";
    return false;
}

};

class Mentor;

class Student {
private:
    int student_id;
    string name;
    int age;
    Sport sports_interests[MAX_SPORTS];
    int sport_count;
    Mentor* mentor_assigned;

public:
    Student(int id = 0, string student_name = "", int student_age = 0) : student_id(id), name(student_name), age(student_age), sport_count(0), mentor_assigned(nullptr) {}
    
    int getStudentId() const { return student_id; }
    string getName() const { return name; }
    int getAge() const { return age; }
    void setAge(int new_age) { age = new_age; }
    
    void registerForMentorship(Mentor* mentor);
    void unregisterFromMentorship();
    void viewMentorDetails() const;

    void updateSportsInterest(const Sport& sport) {
        if (sport_count < MAX_SPORTS) {
            sports_interests[sport_count++] = sport;
        }
    }
};

class Mentor {
private:
    int mentor_id;
    string name;
    Sport sports_expertise[MAX_SPORTS];
    int sport_count;
    int max_learners;
    Student* assigned_learners[MAX_LEARNERS];
    int learner_count;

public:
    Mentor(int id = 0, string mentor_name = "", int max_cap = 0) : mentor_id(id), name(mentor_name), max_learners(max_cap), learner_count(0), sport_count(0) {}
    
    int getMentorId() const { return mentor_id; }
    string getName() const { return name; }
    int getMaxLearners() const { return max_learners; }
    void setMaxLearners(int cap) { max_learners = cap; }
    
    bool assignLearner(Student* student) {
        if (learner_count < max_learners) {
            assigned_learners[learner_count++] = student;
            return true;
        }
        return false;
    }

    bool removeLearner(Student* student) {
        for (int i = 0; i < learner_count; i++) {
            if (assigned_learners[i] == student) {
                for (int j = i; j < learner_count - 1; j++) {
                    assigned_learners[j] = assigned_learners[j + 1];
                }
                learner_count--;
                student->unregisterFromMentorship();
                return true;
            }
        }
        return false;
    }

    void provideGuidance() const {
    cout << "Mentor " << name << " is providing guidance to their learners:\n";
    for (int i = 0; i < learner_count; i++) {
        cout << "- Guiding " << assigned_learners[i]->getName() << " on sports training.\n";
    }
}
    
    void viewLearners() const {
        cout << "Mentor " << name << " has the following learners:\n";
        for (int i = 0; i < learner_count; i++) {
            cout << "- " << assigned_learners[i]->getName() << endl;
        }
    }
};

void Student::registerForMentorship(Mentor* mentor) {
    if (mentor->assignLearner(this)) {
        mentor_assigned = mentor;
        cout << name << " has been assigned to Mentor " << mentor->getName() << "\n";
    } else {
        cout << "Mentor " << mentor->getName() << " is at full capacity.\n";
    }
}

void Student::unregisterFromMentorship() {
    if (mentor_assigned) {
        mentor_assigned->removeLearner(this);
        mentor_assigned = nullptr;
        cout << name << " has been unassigned from their mentor.\n";
    }
}

void Student::viewMentorDetails() const {
    if (mentor_assigned) {
        cout << "Mentor Assigned: " << mentor_assigned->getName() << "\n";
    } else {
        cout << "No mentor assigned.\n";
    }
}

int main() {
    Mentor mentor1(1, "Ali", 3);
    Student student1(101, "Saad", 20);
    Student student2(102, "Ahmed", 22);
    Student student3(103, "Ayesha", 19);
    Student student4(104, "Zain", 21);

    student1.registerForMentorship(&mentor1);
    student2.registerForMentorship(&mentor1);
    student3.registerForMentorship(&mentor1);
    student4.registerForMentorship(&mentor1);

    mentor1.viewLearners();
    student1.viewMentorDetails();

    student1.unregisterFromMentorship();
    mentor1.viewLearners();

    return 0;
}
