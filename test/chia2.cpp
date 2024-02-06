// chia 2 xe
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int minDiff; // Biến toàn cục để lưu lượng chênh lệch nhỏ nhất
vector<int> bestSplit; // Biến toàn cục để lưu cách chia mảng tốt nhất

// Hàm đệ quy để vét hết các trường hợp chia mảng
void findMinDiff(const vector<int>& arr, int index, int sumLeft, int sumRight, vector<int>& currentSplit) {
    if (index == arr.size()) {
        // Nếu đã duyệt hết mảng, kiểm tra và cập nhật lượng chênh lệch nhỏ nhất
        int diff = abs(sumLeft - sumRight);
        if (diff < minDiff) {
            minDiff = diff;
            bestSplit = currentSplit;
        }
        return;
    }

    // Thử chia mảng ở vị trí index
    currentSplit.push_back(index);
    findMinDiff(arr, index + 1, sumLeft + arr[index], sumRight, currentSplit);
    currentSplit.pop_back();

    // Thử không chia mảng ở vị trí index
    findMinDiff(arr, index + 1, sumLeft, sumRight + arr[index], currentSplit);
}

int main() {
    // Nhập số phần tử n
    int n;
    cin >> n;

    // Nhập mảng n phần tử
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    minDiff = INT_MAX; // Khởi tạo giá trị lượng chênh lệch nhỏ nhất là Max Int
    vector<int> currentSplit; // Biến cục bộ để lưu cách chia mảng hiện tại

    // Gọi hàm đệ quy để tìm cách chia mảng
    findMinDiff(arr, 0, 0, 0, currentSplit);

    // In ra lượng chênh lệch nhỏ nhất và cách chia mảng
    cout << minDiff << endl;

    return 0;
}
