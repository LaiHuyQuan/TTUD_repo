// kho báu
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1001;

int n, c[MAX_N][MAX_N];
long long X[MAX_N], Max;
vector<pair<int, int>> V;

// Hàm tính giá trị lớn nhất có thể đạt được tại vị trí i
long long calculateMaxValue(int i) {
    long long result = c[V[i].first][V[i].second];
    for (int j = 0; j < i; j++) {
        if (V[i].first >= V[j].first && V[i].second >= V[j].second) {
            result = max(result, X[j] + c[V[i].first][V[i].second]);
        }
    }
    return result;
}

// Hàm thực hiện thuật toán dynamic programming
void dynamicProgramming() {
    for (int i = 0; i < n; i++) {
        X[i] = calculateMaxValue(i);
        Max = max(Max, X[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, ci;
        cin >> x >> y >> ci;
        V.push_back({x, y});
        c[x][y] = ci;
    }

    sort(V.begin(), V.end());

    dynamicProgramming();

    cout << Max;

    return 0;
}
