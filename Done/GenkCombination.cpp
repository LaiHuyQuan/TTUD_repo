#include <iostream>
#include <vector>

void combinationsHelper(std::vector<std::vector<int>>& result, std::vector<int>& currentCombination, int start, int k, int n) {
    if (k == 0) {
        result.push_back(currentCombination);
        return;
    }

    for (int i = start; i <= n; i++) {
        currentCombination.push_back(i);
        combinationsHelper(result, currentCombination, i + 1, k - 1, n);
        currentCombination.pop_back();
    }
}

std::vector<std::vector<int>> generateCombinations(int k, int n) {
    std::vector<std::vector<int>> result;
    std::vector<int> currentCombination;
    combinationsHelper(result, currentCombination, 1, k, n);
    return result;
}

int main() {
    int k, n;
    std::cin >> k;
    std::cin >> n;

    if (1 <= k && k <= n) {
        std::vector<std::vector<int>> combinations = generateCombinations(k, n);

        for (const auto& combination : combinations) {
            for (int num : combination) {
                std::cout << num << " ";
            }
            std::cout << "\n";
        }
    } 
    return 0;
}
