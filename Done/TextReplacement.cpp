#include <iostream>
#include <string>

using namespace std;

int main() {
    // Đọc xâu P1
    string P1;
    getline(cin, P1);

    // Đọc xâu P2
    string P2;
    getline(cin, P2);

    // Đọc văn bản T
    string T;
    getline(cin, T);

    // Tìm và thay thế các xâu P1 bằng xâu P2 trong văn bản T
    size_t pos = T.find(P1);
    while (pos != string::npos) {
        T.replace(pos, P1.length(), P2);
        pos = T.find(P1, pos + P2.length());
    }

    // In kết quả
    cout << T << endl;

    return 0;
}
