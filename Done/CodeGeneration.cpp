#include <iostream>
#include <vector>
#include <iomanip> // For setw function

using namespace std;

// Function to generate keys for given integers
vector<string> codeGenerate(int n, int L, const vector<int>& integers) {
    vector<string> keys;
    for (int i = 0; i < n; ++i) {
        string key = to_string(integers[i]);
        key = string(L - key.length(), '0') + key;
        keys.push_back(key);
    }
    return keys;
}

int main() {
    // Input
    int n, L;
    cin >> n >> L;

    vector<int> integers(n);
    for (int i = 0; i < n; ++i) {
        cin >> integers[i];
    }

    // Generate keys
    vector<string> keys = codeGenerate(n, L, integers);

    // Output
    for (const auto& key : keys) {
        cout << key << endl;
    }

    return 0;
}
