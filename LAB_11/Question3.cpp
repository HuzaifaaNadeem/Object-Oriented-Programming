#include <iostream>
#include <string>
#include <exception>
using namespace std;

class FileException : public exception {
public:
    virtual const char* what() const noexcept override {
        return "FileException - General file error.";
    }
};

class FileNotFoundException : public FileException {
public:
    const char* what() const noexcept override {
        return "FileNotFoundException - File not found.";
    }
};

class PermissionDeniedException : public FileException {
public:
    const char* what() const noexcept override {
        return "PermissionDeniedException - Access denied.";
    }
};

void readFile(const string& name) {
    if (name == "missing.txt") {
        throw FileNotFoundException();
    } else if (name == "secret.txt") {
        throw PermissionDeniedException();
    } else {
        cout << "Opened file: " << name << endl;
    }
}

int main() {
    string name = "secret.txt";
    try {
        readFile(name);
    } catch (const FileNotFoundException& e) {
        cout << "Reading '" << name << "': " << e.what() << endl;
    } catch (const PermissionDeniedException& e) {
        cout << "Reading '" << name << "': " << e.what() << endl;
    } catch (const FileException& e) {
        cout << "Reading '" << name << "': " << e.what() << endl;
    }
    return 0;
}
