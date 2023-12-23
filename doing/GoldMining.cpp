#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, L1, L2;
    cin >> n >> L1 >> L2;

    vector<int> a(n + 1);
    vector<long long> prefix_sum(n + 1, 0);
    vector<long long> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }

    for (int i = 1; i <= n; ++i) {
        if (i - L1 >= 0) {
            dp[i] = max(dp[i], dp[i - L1] + prefix_sum[i] - prefix_sum[i - L1]);
        }
        if (i - L2 >= 0) {
            dp[i] = max(dp[i], dp[i - L2] + prefix_sum[i] - prefix_sum[i - L2]);
        }
        dp[i] = max(dp[i], dp[i - 1]);
    }

    cout << dp[n] << endl;

    return 0;
}
