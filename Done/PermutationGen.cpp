#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generatePermutations(int n) {
    vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        permutation[i] = i + 1;
    }

    do {
        for (int i = 0; i < n; ++i) {
            cout << permutation[i];
            if (i < n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    } while (next_permutation(permutation.begin(), permutation.end()));
}

int main() {
    int n;
    cin >> n;

    generatePermutations(n);

    return 0;
}
