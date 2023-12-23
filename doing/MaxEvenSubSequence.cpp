#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    int evenCount = 0;
    int oddCount = 0;
    int minEven = INT_MAX;
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        sum += abs(a[i]);

        if (a[i] % 2 == 0) {
            evenCount++;
            minEven = min(minEven, abs(a[i]));
        } else {
            oddCount++;
        }
    }

    if (evenCount == 0) {
        cout << "NOT_FOUND" << endl;
    } else {
        if (sum % 2 == 0) {
            cout << sum << endl;
        } else {
            cout << sum - minEven << endl;
        }
    }

    return 0;
}
