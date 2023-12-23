#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int countPairsWithSum(const vector<int>& arr, int n, int M) {
    int count = 0;
    unordered_set<int> seenValues;

    for (int i = 0; i < n; ++i) {
        int complement = M - arr[i];

        if (seenValues.find(complement) != seenValues.end()) {
            count++;
        }

        seenValues.insert(arr[i]);
    }

    return count;
}

int main() {
    int n, M;
    cin >> n >> M;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = countPairsWithSum(arr, n, M);
    cout << result << endl;

    return 0;
}
