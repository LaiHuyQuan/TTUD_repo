#include <iostream>
#include <vector>

using namespace std;

int minimalNumberOfCoins(vector<int> &coins, int price) {
    if (price == 0) {
        return 0;
    }

    int minCoins = INT_MAX; // Đặt giá trị tối đa ban đầu
    for (int coin : coins) {
        if (coin <= price) {
            int numCoins = 1 + minimalNumberOfCoins(coins, price - coin);
            minCoins = min(minCoins, numCoins);
        }
    }

    return minCoins;
}

int main() {
    vector<int> coins = {1, 5, 10, 100};
    int price = 239;
    int result = minimalNumberOfCoins(coins, price);
    cout << result << endl; 
    
    return 0; 
}
