#include <iostream>
#include <vector>
using namespace std;

void combinationsHelper(vector<vector<int>>& result, vector<int>& currentCombination, int start, int k, int n) {
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

vector<vector<int>> generateCombinations(int k, int n) {
    vector<vector<int>> result;
    vector<int> currentCombination;
    combinationsHelper(result, currentCombination, 1, k, n);
    return result;
}

int main() {
    int n, iYear;
    int count = 0;
    const int MAX =20;
    int arr[MAX];
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    cin >> iYear;

    for(int k = 2; k <= n; k++) {
        vector<vector<int>> combinations = generateCombinations(k, n);
        int sum = 0;
        for (const auto& combination : combinations) {
            for (int num : combination) {
                sum += arr[num];
            }
            if (sum >= iYear){
                count += 1;
            }
        }
    } 
    cout << count / 2;
}
