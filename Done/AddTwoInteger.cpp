#include <iostream>
#include <algorithm>

using namespace std;

string numStr1,numStr2;
string result;

void input(){
    cin >> numStr1;
    cin >> numStr2;
}

// Hàm cộng hai số lớn dưới dạng chuỗi
string addLargeNumbers(const string& num1, const string& num2) {
    int carry = 0;

    // Lặp qua từng chữ số từ phải sang trái
    for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0 || carry > 0; --i, --j) {
        // Lấy giá trị của chữ số tại vị trí i và j
        int digit1 = (i >= 0) ? (num1[i] - '0') : 0;
        int digit2 = (j >= 0) ? (num2[j] - '0') : 0;

        // Tính tổng và cập nhật giá trị carry
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;

        // Lưu chữ số cuối cùng của tổng vào kết quả
        result.push_back((sum % 10) + '0');
    }

    // Đảo ngược kết quả vì chúng ta lưu từ phải sang trái
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    input();
    string sum = addLargeNumbers(numStr1, numStr2);

    cout << sum << endl;

    return 0;
}
