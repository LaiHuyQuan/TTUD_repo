#include <bits/stdc++.h>
using namespace std;

struct MyPair {
    int name;
    int second;

    MyPair(int n, int s) : name(n), second(s) {}

    bool operator>(const MyPair& other) const {
        return second > other.second;
    }
};

int main() {
    int n, m, total_cost = 0;
    cin >> n >> m;

    vector<pair<int, int>> Cities(n);
    vector<int> Checked(n, 0);
    vector<pair<int, int>> Current_situation(n);
    vector<vector<int>> Adj(n);

    for (int i = 0; i < n; i++) {
        int cost, distance;
        cin >> cost >> distance;
        Cities[i] = make_pair(cost, distance);
    }

    for (int i = 0; i < m; i++) {
        int city1, city2;
        cin >> city1 >> city2;
        Adj[city1 - 1].push_back(city2);
        Adj[city2 - 1].push_back(city1);
    }

    priority_queue<MyPair, vector<MyPair>, greater<MyPair>> p;
    p.push(MyPair(1, Cities[0].second));

    Current_situation[0] = make_pair(Cities[0].first, Cities[0].second);
    total_cost = Cities[0].first;
    while (!p.empty()) {
        MyPair a = p.top();
        p.pop();
        if (a.name == n) {
            cout << Current_situation[a.name - 1].first;
            break;
        }
         
        if (Current_situation[a.name - 1].second == 0) {
            total_cost = Cities[a.name - 1].first + Current_situation[a.name - 1].first;
            Current_situation[a.name - 1].second = Cities[a.name - 1].second;
        }

        Checked[a.name - 1] = 1;

        for (const auto& city : Adj[a.name - 1]) {
            if (Checked[city - 1] == 0) {
                p.push(MyPair(city, total_cost));
                Current_situation[city - 1].first = total_cost;
                Current_situation[city - 1].second = Current_situation[a.name - 1].second - 1;
            }
        }
    }

    return 0;
} 