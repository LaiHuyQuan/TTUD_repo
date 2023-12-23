#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Hàm nhân hai số nguyên lớn
string multiply(string num1, string num2) {
    int n = num1.size();
    int m = num2.size();

    // Mảng lưu trữ kết quả của phép nhân
    vector<int> result(n + m, 0);

    // Tính toán từng chữ số và cập nhật kết quả
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j] += sum / 10;
            result[i + j + 1] = sum % 10;
        }
    }

    // Chuyển mảng kết quả thành chuỗi
    string resultStr;
    for (int digit : result) {
        if (!(resultStr.empty() && digit == 0)) {
            resultStr.push_back(digit + '0');
        }
    }

    return resultStr.empty() ? "0" : resultStr;
}

int main() {
    // Nhập số nguyên a và b
    string a, b;
    cin >> a;
    cin >> b;

    // Tính và in ra kết quả
    string result = multiply(a, b);
    cout << result << endl;

    return 0;
}
