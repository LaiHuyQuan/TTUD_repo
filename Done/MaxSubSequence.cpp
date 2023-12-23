#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> dp(n, 0);
    dp[0] = max(0, a[0]);

    for (int i = 1; i < n; ++i) {
        dp[i] = max((long long)a[i], dp[i - 1] + a[i]);
    }

    long long maxWeight = dp[0];

    for (int i = 1; i < n; ++i) {
        maxWeight = max(maxWeight, dp[i]);
    }

    cout << maxWeight << endl;

    return 0;
}
