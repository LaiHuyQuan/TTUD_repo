#include <iostream>

using namespace std;

void inputArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

int findMaxLengthIncreasingSubsequence(int arr[], int n) {
    if (n == 0) {
        return 0;
    }

    int maxLength = 1;
    int currentLength = 1;

    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[i - 1]) {
            currentLength++;
        } else {
            maxLength = max(maxLength, currentLength);
            currentLength = 1;
        }
    }

    maxLength = max(maxLength, currentLength);

    return maxLength;
}

int main() {
    const int size = 15;
    int arr[size];

    inputArray(arr, size);

    int maxLength = findMaxLengthIncreasingSubsequence(arr, size);

    cout << maxLength << endl;

    return 0;
}
