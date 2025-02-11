#include <iostream>
#include <cstring>
using namespace std;

int countVow(const char* inpStr) {
    int vowelCount = 0;
    for (int i = 0; inpStr[i] != '\0'; ++i) {
        char c = tolower(inpStr[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            ++vowelCount;
        }
    }
    return vowelCount;
}

int main() {
    int numStrings;
    cout << "Enter the number of strings: ";
    cin >> numStrings;
    cin.ignore();

    char** stringArray = new char*[numStrings];

    for (int i = 0; i < numStrings; ++i) {
        char temp[100];
        cout << "Enter string " << i + 1 << ": ";
        cin.getline(temp, 100);
        stringArray[i] = new char[strlen(temp) + 1];
        strcpy(stringArray[i], temp);
    }

    cout << "\nStrings in reverse order:" << endl;
    for (int i = numStrings - 1; i >= 0; --i) {
        cout << stringArray[i] << endl;
    }

    char* stringWithMaxVowels = stringArray[0];
    int maxVowelCount = countVow(stringArray[0]);

    for (int i = 1; i < numStrings; ++i) {
        int currentVowelCount = countVow(stringArray[i]);
        if (currentVowelCount > maxVowelCount) {
            maxVowelCount = currentVowelCount;
            stringWithMaxVowels = stringArray[i];
        }
    }

    cout << "\nString with the most vowels: " << stringWithMaxVowels << " (" << maxVowelCount << " vowels)" << endl;

    int totalLength = 0;
    for (int i = 0; i < numStrings; ++i) {
        totalLength += strlen(stringArray[i]);
    }

    double averageLength = (double)totalLength / numStrings;
    cout << "Average length of the strings: " << averageLength << endl;

    for (int i = 0; i < numStrings; ++i) {
        delete[] stringArray[i];
    }
    delete[] stringArray;

    return 0;
}

