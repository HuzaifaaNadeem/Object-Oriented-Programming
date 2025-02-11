#include <iostream>

using namespace std;

int findMaxArea(int arr[], int size) {
    int i = 0;
    int j = size - 1;
    int maxArea = 0;

    while (i < j) {
        int h = (arr[i] < arr[j]) ? arr[i] : arr[j];
        int area = h * (j - i);
        if (area > maxArea) {
            maxArea = area;
        }

        if (arr[i] < arr[j]) {
            i++;
        } else {
            j--;
        }
    }

    return maxArea;
}

int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
	int i = 0;
    int j = size - 1;
    int maxArea = 0;

    while (i < j) {
        int h = (arr[i] < arr[j]) ? arr[i] : arr[j];
        int area = h * (j - i);
        if (area > maxArea) {
            maxArea = area;
        }

        if (arr[i] < arr[j]) {
            i++;
        } else {
            j--;
        }
    }
    cout << "Maximum area: " << maxArea << endl;
    return 0;
}
