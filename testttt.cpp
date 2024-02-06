#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0; // Biến đếm số lượng bộ số thỏa mãn điều kiện

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];

            // Tim phan tu co gia tri bang tong cua 2 so con lai
            auto it = find(arr.begin(), arr.end(), sum);
            if (it != arr.end()) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
