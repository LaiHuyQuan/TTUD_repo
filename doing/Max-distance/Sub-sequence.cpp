#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValidSubset(const vector<int>& positions, int distance, int C) {
    int count = 1;
    int lastPosition = positions[0];

    for (int i = 1; i < positions.size(); ++i) {
        if (positions[i] - lastPosition >= distance) {
            lastPosition = positions[i];
            count++;
            if (count == C)
                return true;
        }
    }

    return false;
}

int findMaximalDistance(const vector<int>& positions, int C) {
    int left = 0;
    int right = positions.back() - positions.front();

    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isValidSubset(positions, mid, C)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, C;
        cin >> N >> C;

        vector<int> positions(N);
        for (int i = 0; i < N; ++i) {
            cin >> positions[i];
        }

        sort(positions.begin(), positions.end());

        // Tìm kiếm dạng sliding window
        int left = 0;
        int right = positions.back() - positions.front();
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (isValidSubset(positions, mid, C)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        cout << result << endl;
    }
    return 0;
}
