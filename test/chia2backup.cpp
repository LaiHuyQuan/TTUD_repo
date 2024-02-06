// chia 2 backup
#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1001;
int n, a[MAX_N], x[MAX_N], sum, Min;

void solution() {
    int sum1 = 0;
    for (int i = 1; i <= n; i++) {
        if (x[i]) sum1 += a[i];
    }
    Min = min(Min, abs(sum - 2 * sum1));
}

void Try(int k) {
    for (int i = 0; i <= 1; i++) {
        x[k] = i;
        if (k == n) solution();
        else Try(k + 1);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    Min = 1e9;
    Try(1);
    cout << Min;
    return 0;
}
