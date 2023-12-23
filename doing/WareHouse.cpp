#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, T, D;
    cin >> N >> T >> D;

    vector<int> a(N + 1); // amount of goods
    vector<int> t(N + 1); // pickup time duration

    // Input amount of goods for each station
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    // Input pickup time duration for each station
    for (int i = 1; i <= N; ++i) {
        cin >> t[i];
    }

    vector<int> dp(T + 1, 0);

    // Dynamic Programming
    for (int i = 1; i <= N; ++i) {
        for (int j = T; j >= t[i]; --j) {
            dp[j] = max(dp[j], dp[j - t[i]] + a[i]);
        }
    }

    // Find the maximum amount of goods picked up
    int maxGoods = 0;
    for (int j = T - D; j <= T; ++j) {
        if (j >= 0) {
            maxGoods = max(maxGoods, dp[j]);
        }
    }

    // Output the result
    cout << maxGoods << endl;

    return 0;
}
