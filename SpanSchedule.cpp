#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, m, d[N]; 
vector<pair<int , int>> a;

void input(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> d[i];
    }

    for (int  i = 0; i < m; i++)
    {   
        pair<int, int> ip;
        cin >> ip.first >> ip.second;
        a.push_back(ip);
    }
    
}

int main(){
    input();
    for (int  i = 0; i < m; i++){
        cout << a[i].first << a[i].second << ' ';
    }
}