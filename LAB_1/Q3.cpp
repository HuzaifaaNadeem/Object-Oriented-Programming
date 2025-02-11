#include <iostream>
using namespace std;

void findIndices(int arr[], int size, int sum, int result[]) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] + arr[j] == sum) {
                result[0] = i;
                result[1] = j;
                return;
            }
        }
    }
}

int main() {
    int sum;
    cout << "Enter the target sum: ";
    cin >> sum;
    cout << "Enter the size of the array: ";
    int size;
    cin >> size;
    int arr[size];
    cout << "Enter " << size << " elements of the array: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    int result[2];
    findIndices(arr, size, sum, result);
    cout << "Output: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}
