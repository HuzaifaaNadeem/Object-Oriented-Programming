#include <iostream>
using namespace std;

class ValidateString {
private:
    string inputStr;

public:
    ValidateString(const string& str) : inputStr(str) {}

    bool isValid() const {
        for (char c : inputStr) {
            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string str1, str2, str3;

    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;
   

    ValidateString obj1(str1);
    ValidateString obj2(str2);
    

    if (obj1.isValid()) {
        cout << "First string is valid: Yes" << endl;
    } else {
        cout << "First string is valid: No" << endl;
    }

    if (obj2.isValid()) {
        cout << "Second string is valid: Yes" << endl;
    } else {
        cout << "Second string is valid: No" << endl;
    }


    return 0;
}
