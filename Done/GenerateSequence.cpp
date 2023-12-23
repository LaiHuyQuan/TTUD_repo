#include <iostream>
#include <vector>

void generateSequences(int n, std::vector<char>& sequence, int index) {
    if (index == n) {
        for (char digit : sequence) {
            std::cout << digit;
        }
        std::cout << std::endl;
        return;
    }

    // Try adding '0'
    sequence[index] = '0';
    generateSequences(n, sequence, index + 1);

    // If the previous digit is '0', try adding '1'
    if (index == 0 || sequence[index - 1] == '0') {
        sequence[index] = '1';
        generateSequences(n, sequence, index + 1);
    }
}

int main() {
    // Input
    int n;
    std::cin >> n;

    // Initialize sequence with n characters
    std::vector<char> sequence(n, '0');

    // Generate and print sequences
    generateSequences(n, sequence, 0);

    return 0;
}
