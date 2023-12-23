#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class SparseTable {
private:
    vector<vector<int>> table;

public:
    SparseTable(const vector<int>& array) {
        int n = array.size();
        int logN = log2(n) + 1;

        table.assign(n, vector<int>(logN));

        for (int i = 0; i < n; ++i) {
            table[i][0] = array[i];
        }

        for (int j = 1; (1 << j) <= n; ++j) {
            for (int i = 0; i + (1 << j) - 1 < n; ++i) {
                table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int left, int right) {
        int k = log2(right - left + 1);
        return min(table[left][k], table[right - (1 << k) + 1][k]);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    int m;
    cin >> m;

    SparseTable sparseTable(array);

    int totalSum = 0;
    for (int k = 0; k < m; ++k) {
        int i, j;
        cin >> i >> j;
        totalSum += sparseTable.query(i, j);
    }

    cout << totalSum << endl;

    return 0;
}
