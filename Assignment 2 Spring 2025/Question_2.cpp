#include <iostream>
#include <string>
using namespace std;

class Ghost {
protected:
    string ghostName;
    int scareLevel;

public:
    Ghost(string name, int level) : ghostName(name), scareLevel(level) {}
    Ghost() : ghostName("Unnamed Ghost"), scareLevel(1) {}

    virtual void haunt() = 0;
    
    int getScareLevel() const {
        return scareLevel;
    }

    string getGhostName() const {
        return ghostName;
    }

    friend ostream& operator<<(ostream& os, const Ghost& ghost) {
        os << "Ghost Name: " << ghost.ghostName << ", Scare Level: " << ghost.scareLevel;
        return os;
    }

    Ghost operator+(const Ghost& other) {
        return Ghost("Combined Ghost", this->scareLevel + other.scareLevel);
    }
};

class Poltergeist : public Ghost {
public:
    Poltergeist(string name, int level) : Ghost(name, level) {}

    void haunt() override {
        cout << "Moving objects around!" << endl;
    }
};

class Banshee : public Ghost {
public:
    Banshee(string name, int level) : Ghost(name, level) {}

    void haunt() override {
        cout << "Screaming loudly!" << endl;
    }
};

class ShadowGhost : public Ghost {
public:
    ShadowGhost(string name, int level) : Ghost(name, level) {}

    void haunt() override {
        cout << "Whispering creepily..." << endl;
    }
};

class ShadowPoltergeist : public ShadowGhost, public Poltergeist {
public:
    ShadowPoltergeist(string name, int level) : Ghost(name, level), ShadowGhost(name, level), Poltergeist(name, level) {}

    void haunt() override {
        cout << "Moving objects while whispering creepily..." << endl;
    }
};

class Visitor {
private:
    string visitorName;
    string braveryLevel;

public:
    Visitor(string name, int bravery) : visitorName(name) {
        if (bravery >= 1 && bravery <= 4) braveryLevel = "Cowardly";
        else if (bravery >= 5 && bravery <= 7) braveryLevel = "Average";
        else if (bravery >= 8 && bravery <= 10) braveryLevel = "Fearless";
        else braveryLevel = "Unknown";
    }

    string getName() const {
        return visitorName;
    }

    string getBraveryLevel() const {
        return braveryLevel;
    }

    string reactToGhost(int ghostScareLevel) {
        int lower, upper;

        if (braveryLevel == "Cowardly") {
            lower = 1;
            upper = 4;
        } else if (braveryLevel == "Average") {
            lower = 5;
            upper = 7;
        } else if (braveryLevel == "Fearless") {
            lower = 8;
            upper = 10;
        } else {
            return "Unknown bravery level!";
        }

        if (ghostScareLevel > upper) {
            return "Screams and runs away!";
        } else if (ghostScareLevel < lower) {
            return "Laughs and taunts the ghost!";
        } else {
            return "Shaky voice, trying to be brave...";
        }
    }
};

class HauntedHouse {
private:
    string houseName;
    Ghost** ghosts;
    int numGhosts;

public:
    HauntedHouse(string name, int numGhosts) : houseName(name), numGhosts(numGhosts) {
        ghosts = new Ghost*[numGhosts];
    }

    ~HauntedHouse() {
        for (int i = 0; i < numGhosts; i++) {
            delete ghosts[i];
        }
        delete[] ghosts;
    }

    string getHouseName() const {
        return houseName;
    }

    void addGhost(Ghost* ghost, int index) {
        if (index < numGhosts) {
            ghosts[index] = ghost;
        }
    }

    Ghost* getGhost(int index) {
        if (index < numGhosts) {
            return ghosts[index];
        }
        return nullptr;
    }
};

void visitHauntedHouse(HauntedHouse &house, Visitor visitors[], int visitorCount) {
    cout << "Visitors are entering the haunted house: " << house.getHouseName() << endl;
    for (int i = 0; i < visitorCount; i++) {
        cout << "\nVisitor: " << visitors[i].getName() << " (Bravery: " << visitors[i].getBraveryLevel() << ")\n";

        for (int j = 0; j < house.numGhosts; j++) {
            Ghost* currentGhost = house.getGhost(j);
            cout << "Encountering Ghost: " << currentGhost->getGhostName() << " (Scare Level: " << currentGhost->getScareLevel() << ")" << endl;
            currentGhost->haunt();
            cout << visitors[i].reactToGhost(currentGhost->getScareLevel()) << endl;
        }
    }
}

int main() {
    Ghost* ghost1 = new Poltergeist("Poltergeist1", 6);
    Ghost* ghost2 = new Banshee("Banshee1", 7);
    Ghost* ghost3 = new ShadowGhost("ShadowGhost1", 5);
    Ghost* ghost4 = new ShadowPoltergeist("ShadowPoltergeist1", 8);

    HauntedHouse house1("Haunted Mansion", 4);
    house1.addGhost(ghost1, 0);
    house1.addGhost(ghost2, 1);
    house1.addGhost(ghost3, 2);
    house1.addGhost(ghost4, 3);

    Visitor visitors[] = {
        Visitor("Alice", 3),
        Visitor("Bob", 6),
        Visitor("Charlie", 9)
    };

    visitHauntedHouse(house1, visitors, 3);

    return 0;
}
