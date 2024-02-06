//tim bo 3 so backup
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10001;
int n, Count, id[MAX_N];
vector<int> V;

// Hàm kiểm tra tồn tại của một giá trị trong mảng
bool exists(int value) {
    return id[value] == 1;
}

// Hàm tính số lượng cặp số có tổng tồn tại trong mảng
int countPairs() {
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (exists(V[i] + V[j])) {
                result++;
            }
        }
    }
    return result;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        V.push_back(a);
        id[a] = 1; // Đánh dấu sự tồn tại
    }

    sort(V.begin(), V.end());

    Count = countPairs();

    cout << Count;

    return 0;
}
