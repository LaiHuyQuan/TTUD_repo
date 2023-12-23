#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, Q;
    cin >> n >> Q;

    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int count = 0;
    int left = 0, right = n - 1;

    while (left < right) {
        int currentSum = a[left] + a[right];
        if (currentSum == Q) {
            count++;
            left++;
            right--;
        } else if (currentSum < Q) {
            left++;
        } else {
            right--;
        }
    }

    cout << count << endl;

    return 0;
}
