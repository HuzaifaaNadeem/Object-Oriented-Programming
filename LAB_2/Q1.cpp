#include <iostream>

using namespace std;

int main() {
    int numberOfElements;

    cout << "Enter the number of elements: ";
    cin >> numberOfElements;

    float* elements = new float[numberOfElements];

    cout << "Enter " << numberOfElements << " numbers:" << endl;
    for (int i = 0; i < numberOfElements; ++i) {
        cout << "Enter number: ";
		cin >> elements[i];
    }

    float Sum = 0.0;
    for (int i = 0; i < numberOfElements; ++i) {
        Sum += elements[i];
    }

    float avg = Sum / numberOfElements;

    float closestNumber = *elements;
    float smallestDifference = avg - *elements;
    if (smallestDifference < 0) {
        smallestDifference = -smallestDifference;
    }

    for (int i = 1; i < numberOfElements; ++i) {
        float currentDifference = avg - elements[i];
        if (currentDifference < 0) {
            currentDifference = -currentDifference;
        }
        if (currentDifference < smallestDifference) {
            smallestDifference = currentDifference;
            closestNumber = elements[i];
        }
    }

    cout << "Average: " << avg << endl;
    cout << "Number closest to the average: " << closestNumber << endl;

    delete[] elements;

    return 0;
}

