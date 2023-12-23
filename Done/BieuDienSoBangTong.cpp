#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9+7;

int countWays(int N) {
    vector<int> dp(N + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; ++j) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }

    return dp[N];
}

int main() {
    // Input
    int N;
    cin >> N;

    // Output
    int result = countWays(N);
    cout << result << endl;

    return 0;
}
