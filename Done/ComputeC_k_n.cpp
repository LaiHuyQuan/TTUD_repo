#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1000;

vector<vector<int>> dp(MAXN, vector<int>(MAXN, 0));

int binomialCoefficient(int k, int n) {
    if (k == 0 || k == n) {
        return 1;
    }

    if (dp[k][n] != 0) {
        return dp[k][n];
    }

    dp[k][n] = (binomialCoefficient(k - 1, n - 1) + binomialCoefficient(k, n - 1)) % MOD;
    return dp[k][n];
}

int main() {
    int k, n;
    cin >> k >> n;

    int result = binomialCoefficient(k, n);

    cout << result << endl;

    return 0;
}
