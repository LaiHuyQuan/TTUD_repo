#include <iostream>
#include <string>
using namespace std;

void generate_binary_sequences(string sequence, int length, int n) {
    if (length == n) {
        cout << sequence << endl;
        return;
    }

    generate_binary_sequences(sequence + "0", length + 1, n);
    generate_binary_sequences(sequence + "1", length + 1, n);
}

int main() {
    int n;
    cin >> n;

    generate_binary_sequences("", 0, n);
}
