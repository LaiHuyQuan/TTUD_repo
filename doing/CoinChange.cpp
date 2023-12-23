#include <bits/stdc++.h>
using namespace std;

int oo = 1e9l;
int D[] = {1, 2, 5, 10, 20, 50, 100, 200, 500};
int k, x;
int iMem[9][10000001];

int minCoin(int i, int x)
{
    if (i == 0 || x < 0)
        return oo;
    if (x == 0)
        return 0;
    if (iMem[i][x] != -1)
        return iMem[i][x];
    iMem[i][x] = min(minCoin(i - 1, x), minCoin(i, x - D[i - 1]) + 1);
    return iMem[i][x];
}

int main(){
    memset(iMem, -1, sizeof(iMem));
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> k >> x;
    cout << minCoin(k, x) << endl;
    return 0;
}