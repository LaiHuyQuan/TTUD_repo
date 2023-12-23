#include <iostream>
#include <cstdint>

using namespace std;

const uint64_t MOD = 1000000007;

uint64_t power(uint64_t base, uint64_t exponent) {
    uint64_t result = 1;
    base = base % MOD;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }

        exponent = exponent >> 1;
        base = (base * base) % MOD;
    }

    return result;
}

int main() {
    uint64_t a, b;
    cin >> a >> b;

    uint64_t result = power(a, b);

    cout << result << endl;

    return 0;
}
